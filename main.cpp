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
    Host Indiv=Host();
    //Test to save hist profil
    char* name="WORKs.ppm";
    unsigned char tab[]={0,255,0,255,0,0,0,0,255};
    Indiv.save_picture(tab,name);
    return 0;
}

