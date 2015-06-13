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

    Triangle* generateTriangles(int whatAmI);
    unsigned int* triangleProfile(Triangle* triangles, int size_triangles);
    unsigned int** matrixGenerator(Triangle* triangles, int size_triangles);
    Triangle* randomGenes(void);
    void mutation(void);
    // Save picture with a matrix of pixel value
    void save_picture(unsigned char * pix, char* picture_name);
    unsigned char* convert_pixel(unsigned int** mat_host, unsigned int** mat_envt, unsigned int** mat_para);
    // Compute the matrix of the 3 profiles and print it
    void format_and_save(unsigned int**, int);
    unsigned int ** pix_to_mat(char * name_pic, int T) const;


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
    unsigned int** matrix;
    int n_genes;

};


#endif // __HOST_H__
