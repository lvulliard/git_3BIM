//****************************************************************************
//
//                                class Environment
//
//****************************************************************************



#ifndef __ENVIRONMENT_H__
#define __ENVIRONMENT_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================

#include <cstdio>
#include <cstdlib>


// ===========================================================================
//                                Project Files
// ===========================================================================

#include "Host.h"


// ===========================================================================
//                              Class declarations
// ===========================================================================


class Environment
{
  public :
   

    // =======================================================================
    //                               Constructors
    // =======================================================================

    Environment(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================

    ~Environment(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
	
    double* getFecondity(void) const;


    // =======================================================================
    //                            Accessors: setters
    // =======================================================================



    // =======================================================================
    //                              Public Methods
    // =======================================================================
    unsigned int** profileFunction(void);
    void newGeneration(void);
    void saveGraphics(void);
    void saveLog(void);
    void saveData(void);


    // =======================================================================
    //                             Public Attributes
    // =======================================================================



  protected :

    // =======================================================================
    //                              Protected Methods
    // =======================================================================


    // =======================================================================
    //                             Protected Attributes
    // =======================================================================
    unsigned int** profile;
    Host* hosts;

	

};


#endif // __ENVIRONMENT_H__
