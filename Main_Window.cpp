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
#include <string>


	
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


	// Attach host_label
	Main_table.attach(host_label,0,1,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	host_label.set_label(DefVal::HOST_LABEL_TEXT);

	// Attach host_combobox
	Main_table.attach(host_combobox,1,2,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	host_combobox.set_wrap_width(DefVal::HOST_COMBOBOX_WRAP_WIDTH);
	host_combobox.set_title(DefVal::HOST_COMBOBOX_TITLE);
	Fill_host_combobox();

	// Attach generation_number_label
	Main_table.attach(generation_number_label,2,3,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	generation_number_label.set_label(DefVal::GENERATION_NUMBER_LABEL_TEXT);

	// Attach generation_number_spinbutton
	Main_table.attach(generation_number_spinbutton,3,4,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	generation_number_spinbutton.set_numeric(TRUE);
	generation_number_spinbutton.set_wrap(TRUE);
	generation_number_spinbutton.set_range(0, DefVal::GENERATION_NUMBER_MAX);
	generation_number_spinbutton.set_increments(1,10);

	
	// Attach start Button
	Main_table.attach(start_button,4,5,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	start_button.set_label(DefVal::START_BUTTON_LABEL);
	start_button.signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::Start_button_clicked));

	// Attach display_image
	Main_table.attach(display_image,0,5,1,2, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	display_image.set(DefVal::DISPLAY_IMAGE_FILE_NAME);

	// Attach statistics_label
	Main_table.attach(statistics_label,0,1,2,3, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	statistics_label.set_label(DefVal::STATISTICS_LABEL_TEXT);

	// Link the option chosen in the combobox to the display of a profile
	host_combobox.signal_changed().connect(sigc::mem_fun(*this, &Main_Window::change_central_pic));

	// Display all widgets
	show_all();
}


// ===========================================================================
//								  Destructor
// ===========================================================================



// ===========================================================================
//								Methods definition
// ===========================================================================

void Main_Window::Fill_host_combobox(void){
	// Add entries to the combobox
	host_combobox.append("host_1");
	host_combobox.append("host_2");
	host_combobox.append("host_3");
	host_combobox.append("host_4");
	host_combobox.append("host_5");
	host_combobox.set_active_text("host_2");
}

void Main_Window::change_central_pic(void)
{
	string text2 = host_combobox.get_active_text(); 
	string f_name = text2 + DefVal::PIC_FORMAT;
	display_image.set(f_name);
}

void Main_Window::Start_button_clicked(void)
{
	int g;
	g = generation_number_spinbutton.get_value();
	printf("Uuuuuuuh: %d\n",g);
}


