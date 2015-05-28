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

// ===========================================================================
//                             Include Project Files
// ===========================================================================
#include "Environment.h"
#include "Host.h"
#include <gtkmm.h>
// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================







// ===========================================================================
//                                   The Main
// ===========================================================================


int main(int argc, char* argv[]) {
	// Initialisation of Gtk:
    Gtk::Main app(argc, argv);
    // Creation of a window, duh!
    Gtk::Window fenetre;
    fenetre.set_title("Coevolution of the vibe !");
    //fenetre.maximize();
    fenetre.resize(800, 600);
    fenetre.set_position(Gtk::WIN_POS_CENTER);
    fenetre.set_border_width(10);

    Gtk::Button bouton("Hummm, I like it when you click me!"); //Création d'un bouton.
    fenetre.add(bouton); //Ajout du bouton à la fenêtre.
    bouton.show(); //Afficher le bouton.


    // Display the window called fenetre => Main loop
    Gtk::Main::run(fenetre);

	printf("Successfully compilated.\n");
    return 0;
}