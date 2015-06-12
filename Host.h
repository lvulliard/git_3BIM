//****************************************************************************
//
//                                class Host
//
//****************************************************************************



#ifndef __HOST_H__
#define __HOST_H__


// ===========================================================================
//                                  Libraries
// ===========================================================================
#include <cstdio>
#include <cstdlib>



// ===========================================================================
//                                Project Files
// ===========================================================================

#include "Triangle.h"


// ===========================================================================
//                              Class declarations
// ===========================================================================


class Host
{
  public :
   

    // =======================================================================
    //                               Constructors
    // =======================================================================

    Host(void);

    // =======================================================================
    //                                Destructor
    // =======================================================================

    ~Host(void);

    // =======================================================================
    //                            Accessors: getters
    // =======================================================================
	
    int getFitness(unsigned int**) const;




    // =======================================================================
    //                            Accessors: setters
    // =======================================================================



    // =======================================================================
    //                              Public Methods
    // =======================================================================

    Triangle* randomGenes(void);
    int* Triangleprofile(void);
    int** matrixGenerator(void);
    void mutation(void);
    void newParasiteGeneration(void);
    // Save picture with a matrix of pixel value
    void save_picture(unsigned char * pix, char* picture_name);
    unsigned char* convert_pixel(int** mat_host, int** mat_envt, int** mat_para);



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

    Triangle parasite;
    int** matrix;
    int n_genes;

};


#endif // __HOST_H__
