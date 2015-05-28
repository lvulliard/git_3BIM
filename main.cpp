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
    fenetre.set_title(DefVal::APP_NAME);
    // Set icon
    fenetre.set_icon_from_file(DefVal::ICON);
    // Set window size
    fenetre.resize(DefVal::WINDOW_WIDTH, DefVal::WINDOW_HEIGHT);
    // Window position
    fenetre.set_position(Gtk::WIN_POS_CENTER);
    fenetre.set_border_width(DefVal::WINDOW_BORDER_WIDTH);
    // Add button
    Gtk::Button bouton(DefVal::BUTTON1_LABEL); 
    fenetre.add(bouton); 
    bouton.show(); 

    // Display the Window object and start the main loop
    Gtk::Main::run(fenetre);

    return 0;
}