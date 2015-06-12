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


int* Host::Triangleprofile(void)
{
  int* profile;
  profile = new int[DefVal::WINDOW_WIDTH]; // An array of 500 values.

  for (int y=0; y<DefVal::WINDOW_WIDTH; y++) {
    profile[y] = 0;  // Initialize all values to 0
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
      if (y > profile[x1])
        profile[x1] = y;
    }
    for (int x2=x+1; x2<=x+w/2; x2++)
    {
      y = int(-2*(h/w)*(x2-x-w/2));
      if (y > profile[x2])
        profile[x2] = y;
    }

  }

  return profile;
}


 // Generates matrix of 0s and 1s depending on weather we're below or above the profile
unsigned int** Host::matrixGenerator(void)
{
  int win_width = DefVal::PIC_WIDTH;
  int win_height = DefVal::PIC_HEIGHT;

  int* prof = Triangleprofile(); 


  unsigned int** mat = new unsigned int*[win_width];            // Creation of lines
  for (int x=0; x<win_width; x++)
  { 
    mat[x] = new unsigned int[win_height];         // Creation of columns
  }

  for (int x=0; x<win_width; x++)        // For each column of my matrix...
  {
  	int temp_max = prof[x]; // max y to fill
  	for (int y=0; y<win_height; y++)
  	{
		if (temp_max >= y)
		{
 			mat[x][y] = 1;
  		}
  		else
  		{
  			mat[x][y] = 0;
  		}
  	}
  }
  return mat;
}



int Host::getFitness(unsigned int** proE) const
{
	// NOT TESTED YET
	//unsigned int** proH = matrice; // host profile
	//unsigned int** proP = getParasiteProfile(); // parasite profile

	float fitness = 1.0;
	for (int x = 0; x < DefVal::PIC_WIDTH; ++x) // parse on x
	{
		for (int y = 0; y < DefVal::PIC_HEIGHT; ++y) // parse on y
		{
			// if (proH[x][y] == 1) && (proE[x][y] == 0) || (proH[x][y] == 0) && (proE[x][y] == 1)	// If a point of the profile is not in the enveloppe, or other way around 
			// {
			// 	fitness += 1; // Not good
			// }
			// if (proH[x][y] == 1) && (proV[x][y] ==1) // If a point of the profile is infected by the parasite
			// {
			// 	fitness += 1; // Not good
			// }
		}	
	}
	return 1/fitness; // Inverse of what is not good
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

unsigned char * Host::convert_pixel (unsigned int** mat_host, unsigned int** mat_envt, unsigned int** mat_para)
{
  unsigned int w=DefVal::PIC_WIDTH;
  unsigned int h=DefVal::PIC_HEIGHT;
  unsigned char * mat_pix= new unsigned char[3*w*h];
  unsigned int x,y;
  //Blue for envt, green for host, red for parasite
  for(x=0; x<w; x++)
  {
    for(y=0; y<h; y++)
    {
      //Host
      if(mat_host[x][y]==1)
      {
        mat_pix[3*(x+(h*w-y*w))+1]=255;
      }
      else
      {
        mat_pix[3*(x+(h*w-y*w))+1]=0;
      }
      //Environment
      if(mat_envt[x][y]==1)
      {
        mat_pix[3*(x+(h*w-y*w))+2]=255;
      }
      else
      {
        mat_pix[3*(x+(h*w-y*w))]=0;
      }
      //Parasite
      if(mat_para[x][y]==1)
      {
        mat_pix[3*(x+(h*w-y*w))]=255;
      }
      else
      {
        mat_pix[3*(x+(h*w-y*w))]=0;
      }
    }
  }
  return mat_pix;
}

void Host::format_and_save(unsigned int** mat_envt, int id)
{
	// host matrix
    unsigned int** mat_host= matrixGenerator();
    // parasite matrix
    unsigned int ** mat_par= matrixGenerator(); // Not implemented yet
    unsigned char * pix= convert_pixel(mat_host, mat_envt, mat_par);
    //printf("%d%s", id, DefVal::PIC_FORMAT.c_str());
    char name[100];
    sprintf(name,"host_%d%s", id, DefVal::PIC_FORMAT.c_str());
    save_picture(pix, name);
}