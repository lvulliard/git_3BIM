//****************************************************************************
//
//								THE MAIN
//
//****************************************************************************
 
 
 
 
// ===========================================================================
//                               Include Libraries
// ===========================================================================
#include <stdlib.h>
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
    Environment env;    

    // Initiate Gtk
    Gtk::Main app(argc, argv);
    // Create the Window object
    Main_Window fenetre;
    // Display the Window object and start the main loop
    Gtk::Main::run(fenetre);
    
    //Giorgia and Noelie test
        Host h;
    int i;
    int x;
    int y;
    
    /*
    Triangle* t = h.randomGenes();
    for (i=0; i<DefVal::N_TRIANGLES_HOST; i++)
      printf("%d %d %d \n",t[i].x, t[i].w, t[i].h);
    
    
    int** p = h.Triangleprofile();
    for (i=0; i<DefVal::WINDOW_WIDTH ;i++)
        printf("%d %d\n",p[0][i],p[1][i]);
    */

    int** m = h.matrixGenerator();
    for (x=0; x<DefVal::WINDOW_WIDTH; x++) {
        for (y=0; y<DefVal::WINDOW_HEIGHT; y++)
            printf ("%d ", m[x][y]);
        printf("\n");
    }

    //Test to save hist profil
    Host Indiv=Host();
    char* name="WORKs.ppm";
    unsigned char tab[]={0,255,0,255,0,0,0,0,255};
    Indiv.save_picture(tab,name);
    return 0;
}

