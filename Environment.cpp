//****************************************************************************
//
//
//
//****************************************************************************




// ===========================================================================
//                                   Libraries
// ===========================================================================

#include <math.h>
#include <stdio.h>
#include <string.h>


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
    hosts[i] = Host(1);
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
  Host new_hosts[DefVal::NB_HOSTS];

  double* fecondity = getFecondity();
  
  int count = 0; // Host we're looking at
  double p = (double)rand() / RAND_MAX; // Random value
  double p_cumul = 0.0; // Sum of the host probabilities
  int done = 0; // Number of new hosts generated

  while(done < DefVal::NB_HOSTS)
  {
    p_cumul += fecondity[count]; //Add the probability the host we're at has a child
    if (p < p_cumul) // If the random value is below the cumulated probabilites
    {
      new_hosts[done] = Host(hosts[count]); // The "count" host reproduces
      //printf("NH : %d, OH : %d; F : %f\n", done, count, new_hosts[done].getFitness( profileFunction() ) );
      done += 1; // One more host has been generated
      count = -1; // We start again to look from the first host
      p_cumul = 0;
      p = (double)rand() / RAND_MAX;
    }
    count += 1;// We go to the next host
  }

  delete [] hosts;
  hosts = new Host [DefVal::NB_HOSTS];
  for(int i = 0; i < DefVal::NB_HOSTS; i++)
  {
    hosts[i] = new_hosts[i];
  }
}
    

void Environment::saveGraphics(void)
{
  // Print profiles in pictures
  for (int i = 0; i < DefVal::NB_HOSTS; ++i)
  {
    //printf("Okay until %d\n", i);
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

double* Environment::getFecondity(void) const
{
  int nb_hosts = DefVal::NB_HOSTS;
  double* fecondity = new double[nb_hosts];
  double all_F= 0.0;

  double check = 0;
  for (int i=0; i<nb_hosts; i++)
  {
    all_F += exp(hosts[i].getFitness(profile) * DefVal::FECONDITY_COEFF);
  }

  for (int i=0; i<nb_hosts; i++) {
    fecondity[i] = exp(hosts[i].getFitness(profile) * DefVal::FECONDITY_COEFF) / all_F;
    //printf("OH : %d, F : %f\n", i, fecondity[i]);
    check += fecondity[i];
 }

  //printf("Td:%f, H:%d\n", check, nb_hosts);
  return fecondity;
}