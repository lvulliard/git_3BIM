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

// ===========================================================================
//                         Declare Miscellaneous Functions
// ===========================================================================







// ===========================================================================
//                                   The Main
// ===========================================================================


int main(int argc, char* argv[]) {
	// Initialisation of Gtk:
    /*Gtk::Main app(argc, argv);
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
    */
    Environment env;
    /*unsigned int** p;
    p = env.profileFunction();
    for (int i=0; i<500;i++)
    {
      printf("%d ",p[0][i]);
      printf("%d\n",p[1][i]);
    }*/
    

    for (int i=0; i<500;i++)
    {
      for (int j=0; j<500; j++)
      {
        printf("%d ",env.matrix[i][j]);
      }
      printf("\n");
    }

	printf("Successfully compilated.\n");
    return 0;
}


// Ajouter au makefile `pkg-config gtkmm-3.0 --cflags --libs`

