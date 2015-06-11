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
//                        	  		Class Host                            	 #
//                                                                           #
//############################################################################


// ===========================================================================
//                                  Constructors
// ===========================================================================

Host::Host(void)
{
  parasites = NULL;
  genes = NULL;
}


// ===========================================================================
//                                  Destructor
// ===========================================================================
Host::~Host(void)
{
	delete [] parasites;
	delete [] genes;
}


//============================================================================
//  							Methods definition
//============================================================================

float Host::getFitness(unsigned int** proE) const
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


float* Host::drawProfile(void)
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







