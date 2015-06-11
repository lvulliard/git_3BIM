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

float Host::getFitness(void) const
{
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







