//****************************************************************************
//
//								THE MAIN
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>

// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "Environment.h"
#include "Host.h"
#include "DefVal.h"
#include "Main_Window.h"

// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================







// ===========================================================================
//                                   The Main
// ===========================================================================


int main(int argc, char* argv[]) {
    srand (time(NULL));
      
    // Initiate Gtk
    Gtk::Main app(argc, argv);
    // Create the Window object
    Main_Window fenetre;
    // Display the Window object and start the main loop
    Gtk::Main::run(fenetre);
    

    /*Host h;
    int i;
    int x;
    int y;
    int size_hosts = DefVal::N_TRIANGLES_HOST;
    int size_paras = DefVal::N_TRIANGLES_PARASITE;
    */

    //Giorgia and Noelie test
    // Host h;
    // int i;
    // int x;
    // int y;
    

    /*
    Triangle* t = h.generateTriangles(1);
    for (i=0; i<size_paras; i++)
        printf("%d %f %f \n",t[i].x, t[i].w, t[i].h);*/
    
    /*
    int* p = h.triangleProfile(t,size_paras);
    for (i=0; i<DefVal::PIC_WIDTH; i++)
        printf("%d %d\n",i,p[i]);*/
    


    /*
    int** m = h.matrixGenerator(t,size_paras);
    int** p = h.Triangleprofile();
    for (i=0; i<DefVal::WINDOW_WIDTH ;i++)
        printf("%d %d\n",p[0][i],p[1][i]);
    for (x=0; x<DefVal::PIC_WIDTH; x++) {
        for (y=0; y<DefVal::PIC_HEIGHT; y++)
            printf ("%f ", m[x][y]);
        printf("\n");
    }*/


    return 0;
}

