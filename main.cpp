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
#include <gtkmm/main.h>
#include <gtkmm/window.h>

// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "Environment.h"
#include "Host.h"
//#include <gtkmm.h>
// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================







// ===========================================================================
//                                   The Main
// ===========================================================================


int main(int argc, char* argv[]) {
    // Initiate Gtk
    Gtk::Main app(argc, argv);
    // Create the Window object
    Gtk::Window fenetre;
    // Set the title
    fenetre.set_title("Coevolution model");
    // Set icon
    fenetre.set_icon_from_file("icon.png");
    // Display the Window object and start the main loop
    Gtk::Main::run(fenetre);
    return 0;
}