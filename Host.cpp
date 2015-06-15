//****************************************************************************
//
//
//
//****************************************************************************




// ===========================================================================
//                                   Libraries
// ===========================================================================

#include <math.h>

// ===========================================================================
//                                 Project Files
// ===========================================================================

#include "Host.h"
#include "DefVal.h"


//############################################################################
//                                                                           #
//                        	  		Class Host                              	 #
//                                                                           #
//############################################################################


// ===========================================================================
//                                  Constructors
// ===========================================================================

Host::Host(void)
{
  // Called as the default constructor. We want to avoid any unnecessary computations in this case
}

Host::Host(int useless_int)
{
  nb_triangles_h = DefVal::N_TRIANGLES_HOST;
  host_triangles = generateTriangles(0,nb_triangles_h);
  nb_triangles_p = DefVal::N_TRIANGLES_PARASITE;
  paras_triangles = generateTriangles(1,nb_triangles_p);   
  //printf("Host generation ...\n");
}

Host::Host(const Host &h2)
{
  nb_triangles_h = DefVal::N_TRIANGLES_HOST;
  nb_triangles_p = DefVal::N_TRIANGLES_PARASITE;
  host_triangles = new Triangle [nb_triangles_h];
  paras_triangles = new Triangle [nb_triangles_p];
  for(int i = 0; i < nb_triangles_h; i++)
  {
    host_triangles[i].x = h2.host_triangles[i].x;
    host_triangles[i].w = h2.host_triangles[i].w;
    host_triangles[i].h = h2.host_triangles[i].h;
  }
  for(int i = 0; i < nb_triangles_p; i++)
  {
    paras_triangles[i].x = h2.paras_triangles[i].x;
    paras_triangles[i].w = h2.paras_triangles[i].w;
    paras_triangles[i].h = h2.paras_triangles[i].h;
  } 
 }


// ===========================================================================
//                                  Destructor
// ===========================================================================
Host::~Host(void)
{
  // delete [] host_triangles;
  // delete [] paras_triangles;
}


//============================================================================
//  							Methods definition
//============================================================================

// Takes 0: hosts or 1:parasites as parameter and returns a table of triangles with random but controlled attributes
Triangle* Host::generateTriangles(int whatAmI, int howMany)
{
  int win_width = DefVal::PIC_WIDTH;
  int wmin = 10;
  int hmin = 10;
  int wmax;
  int hmax;
  int n_triangles = howMany;

  if (whatAmI==0){
    wmax = int(DefVal::PIC_WIDTH*DefVal::HOST_WIDTH/100.0);
    hmax = int(DefVal::PIC_HEIGHT*DefVal::HOST_HEIGHT/100.0);

  } else if (whatAmI==1) {
    wmax = int(DefVal::PIC_WIDTH*DefVal::PARASITE_WIDTH/100.0);
    hmax = int(DefVal::PIC_HEIGHT*DefVal::PARASITE_HEIGHT/100.0);
  }

  Triangle* triangles;
  triangles = new Triangle[n_triangles];
 
  for (int i=0; i<n_triangles; i++) 
  {
    int random_x = 10+(rand()%(int)(win_width-20+1));   // Position of triangle (random in range(10,win_width))
    int random_w = wmin+(rand()%(int)(wmax-wmin+1));         // Random number btw wmin and wmax
    int random_h = hmin+(rand()%(int)(hmax-hmin+1));         // Random number btw hmin and hmax

    if (random_w%2 == 1)
      random_w-=1;

    triangles[i].x = random_x;
    triangles[i].w = random_w;
    triangles[i].h = random_h;
  }

  // Check boundaries
  for (int i=0; i<n_triangles; i++)
  {
    if (triangles[i].x-0.5*triangles[i].w < 0)            // Checks if triangle is too much on the left...
      triangles[i].w = 2*triangles[i].x;                  // ...and corrects its width
    if (triangles[i].x+0.5*triangles[i].w > win_width)    // Checks if triangle is too much on the right
      triangles[i].w = 2*(win_width-triangles[i].x);
  }


  return triangles;
}

unsigned int* Host::triangleProfile(Triangle* triangles, int size_triangles)
{
  unsigned int* profile;
  profile = new unsigned int[DefVal::PIC_WIDTH]; // An array of 500 values.
  int y;
  for (y=0; y < DefVal::PIC_WIDTH; y++) {
    profile[y] = 0; // Initialize all values to 0
  }
  for (int i=0; i<size_triangles; i++)
  {
    //printf("%d %f %f %f\n", i, triangles[i].h, triangles[i].w, triangles[i].x);  
    int x = triangles[i].x;
    int w = triangles[i].w;
    int h = triangles[i].h;
    if (w != 0){
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
  }
  return profile;
}

// Generates matrix of 0s and 1s depending on weather we're below or above the profile
unsigned int** Host::matrixGenerator(Triangle* triangles, int size_triangles)

{
  int win_width = DefVal::PIC_WIDTH;
  int win_height = DefVal::PIC_HEIGHT;
  unsigned int* prof = triangleProfile(triangles, size_triangles);

  unsigned int** mat = new unsigned int*[win_width]; // Creation of lines
  for (int x=0; x<win_width; x++)
    mat[x] = new unsigned int[win_height]; // Creation of columns

  for (int x=0; x<win_width; x++)        // For each column of my matrix...
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

unsigned int ** Host::pix_to_mat(char * name_pic, int count) const
{
  unsigned int w=DefVal::PIC_WIDTH;
  unsigned int h=DefVal::PIC_HEIGHT;
  unsigned char* pix=new unsigned char [3*w*h];
  unsigned int** matH = new unsigned int*[w]; // Creation of lines
  int x, y;
  for (x=0; x<w; x++)
    matH[x] = new unsigned int[h]; // Creation of columns
  
  FILE * fi=fopen(name_pic, "rb");
  fread(pix,sizeof(unsigned char), 3*w*h, fi);
  for(x=0; x<w; x++)
  {
    for(y=0; y<h; y++)
    {
      if(pix[count]==255)
      {
        matH[x][h-y-1]=1;
      }
      else
      {
        matH[x][h-y-1]=0; 
      }
      count++;
    }
  }
  fclose(fi); // MARIANNE!
  delete pix;
  return matH;
}



double Host::getFitness(unsigned int** proE)
{
  unsigned int** proH = matrixGenerator(host_triangles,nb_triangles_h); // host profile
  unsigned int** proP = matrixGenerator(paras_triangles,nb_triangles_p); // parasite profile
	
  float fitness = 1.0;
	
  for (int x = 0; x < DefVal::PIC_WIDTH; ++x) // parse on x
	{
		for (int y = 0; y < DefVal::PIC_HEIGHT; ++y) // parse on y
		{
			if ( ((proH[x][y] == 1) && (proE[x][y] == 0)) || ((proH[x][y] == 0) && (proE[x][y] == 1))  )	// If a point of the profile is not in the enveloppe, or other way around 
			{
				fitness += 1; // Not good
			}
			if ((proH[x][y] == 1) && (proP[x][y] ==1)) // If a point of the profile is infected by the parasite
			{
				fitness += 1; // Not good
			}
		}	
	}
	return 1/fitness; // Inverse of what is not good
}


void Host::mutation(void) 
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
  fclose(picture); // MARIANNE!
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
        // (h-1 - y)*w + x
        mat_pix[3*(x+(h-y-1)*w)+1]=255;
      }
      else
      {
        mat_pix[3*(x+(h-y-1)*w)+1]=0;
      }
      //Environment
      if(mat_envt[x][y]==1)
      {
        mat_pix[3*(x+(h-y-1)*w)+2]=255;
      }
      else
      {
        mat_pix[3*(x+(h-y-1)*w)+2]=0;
      }
      //Parasite
      if(mat_para[x][y]==1)
      {
        mat_pix[3*(x+(h-y-1)*w)]=255;
      }
      else
      {
        mat_pix[3*(x+(h-y-1)*w)]=0;
      }
    }
  }
  return mat_pix;
}

void Host::format_and_save(unsigned int** mat_envt, int id)
{
	// host matrix
    unsigned int** mat_host= matrixGenerator(host_triangles, DefVal::N_TRIANGLES_HOST);
    // parasite matrix
    unsigned int ** mat_par= matrixGenerator(paras_triangles, DefVal::N_TRIANGLES_PARASITE);
    unsigned char * pix= convert_pixel(mat_host, mat_envt, mat_par);
    char name[100];
    sprintf(name,"host_%d%s", id, DefVal::PIC_FORMAT.c_str());
    save_picture(pix, name);
}

Triangle* Host::evolutionTriangles(void)
{
  // Triangle* t = host_triangles;
  // int n_triangles = DefVal::N_TRIANGLES_HOST;
  // Triangle* new_t;
  // new_t = new Triangle[n_triangles];
  // int win_width= DefVal::HOST_EVO_X;
  // int wmin=DefVal::HOST_EVO_W_MIN;
  // int wmax=DefVal::HOST_EVO_W_MAX;
  // int hmin=DefVal::HOST_EVO_H_MIN;
  // int hmax=DefVal::HOST_EVO_H_MAX;
  // int W= (DefVal::HOST_WIDTH*DefVal::WINDOW_WIDTH)/100;
  // int H=(DefVal::HOST_HEIGHT*DefVal::WINDOW_HEIGHT)/100;
  // for (int i=0; i<n_triangles; i++) 
  // {
  //   int random_x = rand()%(int)(win_width+1);   // Position of triangle (random in range(0,win_width))
  //   int random_w = wmin+(rand()%(int)(wmax-wmin+1));         // Random number btw wmin and wmax
  //   int random_h = hmin+(rand()%(int)(hmax-hmin+1));         // Random number btw hmin and hmax
  //   if (random_w%2 == 1)
  //     random_w-=1;
       
  //   int r1=rand()%(2);
  //   if (r1==0) {new_t[i].x = t[i].x+random_x;}
  //   else {new_t[i].x = t[i].x-random_x;}
  //   int r2=rand()%(2);
  //   if (r2==0) {new_t[i].w = t[i].w+random_w;}
  //   else {new_t[i].w = t[i].w-random_w;}
  //   int r3=rand()%(2);
  //   if (r3==0) {new_t[i].h = t[i].h+random_h;}
  //   else {new_t[i].h = t[i].h-random_h;}

  //   //printf("%d %d %d\n", t[i].x, t[i].w, t[i].h);
  // }
  // // Check boundaries
  // for (int i=0; i<n_triangles; i++)
  // {
  //   // Checks if triangle is too much on the left or rigth...
  //   //if so, keep the old values of t
  //   if ( (new_t[i].x - int(0.5*new_t[i].w) < 0) || (new_t[i].x+int(0.5*new_t[i].w) > DefVal::PIC_WIDTH) ) 
  //   {
  //     new_t[i].x = t[i].x;
  //     new_t[i].w = t[i].w;
  //     new_t[i].h= t[i].h;
  //   }
  //   // Checks if triangle is too large...
  //   if (new_t[i].w>W | new_t[i].w<0)
  //     new_t[i].w = t[i].w; 
  //   // Checks if triangle is too hight...
  //   if (new_t[i].h>H | new_t[i].h<0)
  //     new_t[i].h = t[i].h; 
  // }
  // return new_t;
}
