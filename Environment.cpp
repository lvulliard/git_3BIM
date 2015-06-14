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
void Environment::newGeneration(void)
{
  Host* new_hosts[DefVal::NB_HOSTS];

//   int new_size=0;
  
//   Host* new_hosts = new Host[DefVal::NB_HOSTS];

//   int count = 0;
//   int* fecondity = getFecondity();
//   for (int k=0; k<DefVal::NB_HOSTS; k++){
//       for(int i = 0; i < fecondity[k]; i++){
//         new_hosts[count].paras_triangles = hosts[k].paras_triangles;
//         new_hosts[count].host_triangles = hosts[k].evolutionTriangles(); 
//         count++;
//       }
//     }

//   delete[] hosts;
//   hosts = new_hosts;
}
    

void Environment::saveGraphics(void)
{
  // Print profiles in pictures
  for (int i = 0; i < DefVal::NB_HOSTS; ++i)
  {
    hosts[i].format_and_save(profileFunction(),i);
  }
  getFecondity();
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

int* Environment::getFecondity(void) const
{
  int nb_hosts = DefVal::NB_HOSTS;
  int* fecondity = new int[nb_hosts];
  double all_F=0;

  for (int i=0; i<nb_hosts; i++)
  {
    all_F += exp(hosts[i].getFitness(profile) * DefVal::FECONDITY_COEFF);
  }

  for (int i=0; i<nb_hosts; i++) {
    fecondity[i] = round(nb_hosts* exp(hosts[i].getFitness(profile) * DefVal::FECONDITY_COEFF) /all_F);
    printf("F : %d, i : %d\n", fecondity[i], i);
  }
  return fecondity;
}