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
	
    double getFitness(unsigned int**);




    // =======================================================================
    //                            Accessors: setters
    // =======================================================================



    // =======================================================================
    //                              Public Methods
    // =======================================================================

    Triangle* generateTriangles(int whatAmI, int howMany);
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
    Triangle* evolutionTriangles(void);



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
    unsigned int** matrix;
    int nb_triangles_h;
    int nb_triangles_p;
    Triangle* host_triangles;
    Triangle* paras_triangles;

};


#endif // __HOST_H__
