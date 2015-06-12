//****************************************************************************
//
//
//
//****************************************************************************




// ===========================================================================
//                                   Libraries
// ===========================================================================

#include <math.h>
#include <time.h>

// ===========================================================================
//                                 Project Files
// ===========================================================================

#include "Host.h"
#include "DefVal.h"

//############################################################################
//                                                                           #
//                        	  		Class Host                            	 #
//                                                                           #
//############################################################################


// ===========================================================================
//                                  Constructors
// ===========================================================================

Host::Host(void)
{
  matrix=NULL;
  n_genes = DefVal::N_TRIANGLES_HOST;
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Host::~Host(void)
{
	delete [] matrix;
}


//============================================================================
//  							Methods definition
//============================================================================

// Takes the number of genes as parameter and returns a table of triangles with random but controlled attributes
Triangle* Host::randomGenes(void)
{
  srand (time(NULL));
  int win_width = DefVal::WINDOW_WIDTH;
  Triangle* genes;
  genes = new Triangle[n_genes];
 
  for (int i=0; i<n_genes; i++) 
  {
    int random_x = 10+(rand()%(int)(win_width-10+1));   // Position of triangle (random in range(10,win_width))
    int random_w = 10+(rand()%(int)(100-10+1));         // Random number btw 10 and 100
    int random_h = 10+(rand()%(int)(100-50+1));         // Random number btw 10 and 100

    if (random_w%2 == 1)
      random_w-=1;

    genes[i].x = random_x;
    genes[i].w = random_w;
    genes[i].h = random_h;

    //printf("%d %d %d\n", genes[i].x, genes[i].w, genes[i].h);
  }

  // Check boundaries
  for (int i=0; i<n_genes; i++)
  {
    if (genes[i].x-0.5*genes[i].w < 0)            // Checks if triangle is too much on the left...
      genes[i].w = 2*genes[i].x;                  // ...and corrects its width
    if (genes[i].x+0.5*genes[i].w > win_width)    // Checks if triangle is too much on the right
      genes[i].w = 2*(win_width-genes[i].x);
  }


  return genes;
}


int** Host::Triangleprofile(void)
{
  int** profile;
  profile = new int*[2]; // Table of 2 pointers
  for (int i=0; i<2; i++)
    profile[i] = new int[DefVal::WINDOW_WIDTH]; // Each pointer points to an array of 500 values.

  for (int y=0; y<DefVal::WINDOW_WIDTH; y++) {
    profile[1][y] = 0;      // Initialize all y to 0 (not necessary for x)
    profile[0][y] = y;
  }

  Triangle* genes= randomGenes();

  for (int i=0; i<n_genes; i++)
  {
    int x = genes[i].x;
    int w = genes[i].w;
    int h = genes[i].h;

    int y = 0;

    
    for (int x1=x-w/2; x1<=x; x1++)
    {
      y = int(2*(h/w)*(x1-x+w/2));
      if (y > profile[1][x1])
        profile[1][x1] = y;
    }
    for (int x2=x+1; x2<=x+w/2; x2++)
    {
      y = int(-2*(h/w)*(x2-x-w/2));
      if (y > profile[1][x2])
        profile[1][x2] = y;
    }

  }

return profile;
}


 // Generates matrix of 0s and 1s depending on weather we're below or above the profile
int** Host::matrixGenerator(void)
{
  int win_width = DefVal::WINDOW_WIDTH;
  int win_height = DefVal::WINDOW_HEIGHT;

  int** prof = Triangleprofile(); 


  int** mat = new int*[win_height];            // Creation of lines
  for (int y=0; y<win_height; y++) 
    mat[y] = new int[win_width];         // Creation of columns


  for (int x=0; x<win_width; x++)        // For each column of my matrix...
  {
    if (prof[1][x] > 0) {
      for (int y=0; y<=prof[1][x]; y++) {      // ...for each y below the profile...
        mat[x][y]=1;                       // ...put 1
      }
    } else 
      mat[x][0]=0;

    for (int y=prof[1][x]+1; y<win_height; y++)    // For each point above...
      mat[x][y]=0;                                 // ...put 0
    
  }
  return mat;
}



int Host::getFitness(int** m_env, int** m_host, int**m_par) const
{
  int win_width = DefVal::WINDOW_WIDTH;
  int win_height = DefVal::WINDOW_HEIGHT;

  int f = 0;

  for (int x=0; x<win_width; x++)
  {
    for (int y=0; y<win_height; y++)
    {
      int e = m_env[x][y];
      int h = m_host[x][y];
      int p = m_par[x][y];

      if (e==0 && h==0 && p==0)
        f+=0;
      else if (e==0 && h==1 && p==0)
        f-=1;
      else if (e==1 && h==1 && p==0)
        f+=1;
      else if (e==1 && h==1 && p==1)
        f-=1;
      else if (e==1 && h==0 && p==1)
        f-=1;
      else if (e==1 && h==0 && p==0)
        f-=1;
    }
  } 
  return f;
}


void Host::mutation(void) 
{
}


void Host::newParasiteGeneration(void)
{
}

void Host::save_picture(unsigned char* mat_pix, char * picture_name) //pix is an array 1D
{	
	//mat_pix is an array 1D which contains values for each canal (RGB,RGB,RGB....)
	FILE *picture=fopen(picture_name, "wb");
	unsigned int H=DefVal::PIC_HEIGHT;
	unsigned int W=DefVal::PIC_WIDTH;
	fprintf(picture, "P6\n %d %d\n %d\n",W,H,DefVal::MAX_VAL_PICTURE);	
	fwrite(mat_pix,sizeof(unsigned char),3*W*H, picture);
  //delete [] mat_pix;
}




//new int[win_width]




