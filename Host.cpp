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
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Host::~Host(void)
{
}


//============================================================================
//  							Methods definition
//============================================================================

// Takes 0: hosts or 1:parasites as parameter and returns a table of triangles with random but controlled attributes
Triangle* Host::generateTriangles(int whatAmI)
{
  srand (time(NULL));
  int win_width = DefVal::PIC_WIDTH;
  int wmin = 10;
  int hmin = 10;
  int wmax;
  int hmax;
  int n_triangles;
  if (whatAmI==0){
    wmax = int(DefVal::PIC_WIDTH*DefVal::HOST_WIDTH/100);
    hmax = int(DefVal::PIC_HEIGHT*DefVal::HOST_HEIGHT/100);
    n_triangles = DefVal::N_TRIANGLES_HOST;
  } else if (whatAmI==1) {
    wmax = int(DefVal::PIC_WIDTH*DefVal::PARASITE_WIDTH/100);
    hmax = int(DefVal::PIC_HEIGHT*DefVal::PARASITE_HEIGHT/100);
    n_triangles = DefVal::N_TRIANGLES_PARASITE;
  }
  Triangle* triangles;
  triangles = new Triangle[n_triangles];

  for (int i=0; i<n_triangles; i++) 
  {
    int random_x = 10+(rand()%(int)(win_width-20+1)); // Position of triangle (random in range(10,win_width))
    int random_w = wmin+(rand()%(int)(wmax-wmin+1)); // Random number btw wmin and wmax
    int random_h = hmin+(rand()%(int)(hmax-hmin+1)); // Random number btw hmin and hmax

    if (random_w%2 == 1)
      random_w-=1;
    triangles[i].x = random_x;
    triangles[i].w = random_w;
    triangles[i].h = random_h;
    //printf("%d %d %d\n", random_x, random_w, random_h); 
    //printf("%d %f %f\n", triangles[i].x, triangles[i].w, triangles[i].h);
    
    }
  // Check boundaries
  for (int i=0; i<n_triangles; i++)
  {
    if (triangles[i].x-0.5*triangles[i].w < 0) // Checks if triangle is too much on the left...
      triangles[i].w = 2*triangles[i].x; // ...and corrects its width
    if (triangles[i].x+0.5*triangles[i].w > win_width) // Checks if triangle is too much on the right
      triangles[i].w = 2*(win_width-triangles[i].x);
  }

  return triangles;
}

int* Host::triangleProfile(Triangle* triangles, int size_triangles)
{
  int* profile;
  profile = new int[DefVal::PIC_WIDTH]; // An array of 500 values.
  int y;
  for (y=0; y<int(DefVal::PIC_WIDTH); y++) {
    profile[y] = 0; // Initialize all values to 0
  }
  for (int i=0; i<size_triangles; i++)
  {
    int x = triangles[i].x;
    int w = triangles[i].w;
    int h = triangles[i].h;

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
int** Host::matrixGenerator(Triangle* triangles, int size_triangles)
{
  int win_width = DefVal::PIC_WIDTH;
  int win_height = DefVal::PIC_HEIGHT;
  int* prof = triangleProfile(triangles, size_triangles);

  int** mat = new int*[win_width]; // Creation of lines
  for (int x=0; x<win_width; x++)
    mat[x] = new int[win_height]; // Creation of columns
  
  for (int x=0; x<win_width; x++) // For each column of my matrix...
  {
    int temp_max = prof[x]; // max y to fill
    for (int y=0; y<win_height; y++)
    {
      if (temp_max >= y)
        mat[x][y] = 1;
      else
        mat[x][y] = 0;
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



void Host::save_picture(unsigned char * pix, char * picture_name) //pix is an array 1D
{	
	//pix is an array 1D which contains values for each canal (RGB,RGB,RGB....)
	FILE *picture=fopen(picture_name, "wb");
	unsigned int H=DefVal::PIC_HEIGHT;
	unsigned int W=DefVal::PIC_WIDTH;
	fprintf(picture, "P6\n %d %d\n %d",W,H,DefVal::MAX_VAL_PICTURE);	
	fwrite(pix,sizeof(unsigned char),W*H*3, picture);
}

