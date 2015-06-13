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

#include "Environment.h"
#include "DefVal.h"
#include "Host.h"

//############################################################################
//                                                                           #
//                        	  		Class Environment                       	 #
//                                                                           #
//############################################################################


// ===========================================================================
//                                  Constructors
// ===========================================================================

Environment::Environment(void)
{
  profile = profileFunction();

  // Create a table of NB_HOSTS hosts
  hosts = new Host[DefVal::NB_HOSTS];
  for (int i = 0; i < DefVal::NB_HOSTS ; i++)
  {
    hosts[i] = Host();
  }  
}

// ===========================================================================
//                                  Destructor
// ===========================================================================
Environment::~Environment(void)
{
  delete [] hosts;
}


//============================================================================
//  							Methods definition
//============================================================================

int* Environment::getFecondity(void) const
{
}


void Environment::newGeneration(void)
{
}
    

void Environment::runGraphics(void)
{
  // Print profiles in pictures
  for (int i = 0; i < DefVal::NB_HOSTS; ++i)
  {
    hosts[i].format_and_save(profileFunction(),i);
  }
}
    

void Environment::saveLog(void)
{
}

unsigned int** Environment::profileFunction(void) 
{ 
  unsigned int** profile;
  profile = new unsigned int*[DefVal::PIC_WIDTH]; // Width of the simulation
  for (int i=0; i<DefVal::PIC_WIDTH; i++) {
    profile[i] = new unsigned int[DefVal::PIC_HEIGHT];  // Each pointer points to an array of the height of the picture
  }
  
  for (int x=0; x<DefVal::PIC_WIDTH; x++) { // parse on x
    for (int y=0; y<DefVal::PIC_HEIGHT; y++) { // parse on y
   	 if (y <= int(( double(DefVal::PIC_HEIGHT)*130.1/500.1)*(0.5*cos( ( x /( (DefVal::PIC_WIDTH/500.1)*90.1) ) - 2.85) +cos(3*(( x /( (DefVal::PIC_WIDTH/500.1)*90.1) ) - 2.85))+0.5*sin(7*(( x /( (DefVal::PIC_WIDTH/500.1)*90.1) ) - 2.85)) +0.5*sin((( x /( (DefVal::PIC_WIDTH/500.1)*90.1) ) - 2.85)+1.71)) + 130 ) ) {
   	 	profile[x][y] = 1;
   	 }
   	 else {
   	 	profile[x][y] = 0;
   	 }
    }
  }

  return profile;
}







