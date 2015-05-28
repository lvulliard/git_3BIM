//****************************************************************************
//
//								MAIN_WINDOW CPP
//
//****************************************************************************




// ===========================================================================
//								   Libraries
// ===========================================================================


// ===========================================================================
//								 Project Files
// ===========================================================================

#include "DefVal.h"
#include "Main_Window.h"



//############################################################################
//																			 #
//							  Class Main_Window		  						 #
//																			 #
//############################################################################


// ===========================================================================
//								  Constructors
// ===========================================================================


Main_Window::Main_Window(void) {
	// Set the title
	set_title(DefVal::APP_NAME);
	// Set icon
	set_icon_from_file(DefVal::ICON);
	// Set window size
	resize(DefVal::WINDOW_WIDTH, DefVal::WINDOW_HEIGHT);
	// Window position
	set_position(Gtk::WIN_POS_CENTER);

	
	Main_table.resize(5,3); // Resize table
	add(Main_table); // Add table container

	// Attach start Button
	Main_table.attach(start_button, 4, 5, 0, 1, Gtk::FILL, Gtk::FILL,DefVal::BUTTONS_MARGIN_SIZE,DefVal::BUTTONS_MARGIN_SIZE);
	//add(start_button);
	start_button.set_label(DefVal::START_BUTTON_LABEL);

	// Display all widgets
	show_all();
}


// ===========================================================================
//								  Destructor
// ===========================================================================



// ===========================================================================
//								Methods definition
// ===========================================================================