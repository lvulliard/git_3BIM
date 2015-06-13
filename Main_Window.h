//****************************************************************************
//
//								MAIN_WINDOW H
//
//****************************************************************************


#ifndef DEF_MAIN_WINDOW
#define DEF_MAIN_WINDOW

// ===========================================================================
//								Include Libraries
// ===========================================================================
#include <gtkmm/button.h>
#include <gtkmm/main.h>
#include <gtkmm/window.h>
#include <gtkmm/table.h>
#include <gtkmm/label.h>
#include <gtkmm/spinbutton.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/image.h>
#include <string>

#include <gtkmm/actiongroup.h>
#include <gtkmm/box.h>
#include <gtkmm/menu.h>
#include <gtkmm/menubar.h>
#include <gtkmm/menuitem.h>
#include <gtkmm/adjustment.h>

// ===========================================================================
//							 Include Project Files
// ===========================================================================


// ===========================================================================
//								Class declarations
// ===========================================================================



class Main_Window : public Gtk::Window {

	public :

	// =======================================================================
	//								Constructors
	// =======================================================================


	 	Main_Window(void);


	// =======================================================================
	//								Destructor
	// =======================================================================


	// =======================================================================
	//							Accessors: getters
	// =======================================================================


	// =======================================================================
	//							Accessors: setters
	// =======================================================================



	// =======================================================================
	//								Public Methods
	// =======================================================================
        void Fill_host_combobox(void);
        void Start_button_clicked(void);
		// Change the central picture displaying an host profile 
		void change_central_pic(void);

	// =======================================================================
	//							 Public Attributes
	// =======================================================================


	protected :

	// =======================================================================
	//								Protected Methods
	// =======================================================================


	// =======================================================================
	//							 Protected Attributes
	// =======================================================================
		Gtk::Table Main_table;
        Gtk::Button start_button;
        Gtk::Label generation_number_label;
        Gtk::Label host_label;
        Gtk::Label host_number_label;
        Gtk::Label parasite_number_label;
        Gtk::Label statistics_label;
        Gtk::SpinButton generation_number_spinbutton;
        Gtk::SpinButton host_number_spinbutton;
        Gtk::SpinButton parasite_number_spinbutton;
        Gtk::ComboBoxText host_combobox;
        Gtk::Image display_image;

		Gtk::Table legend_table;
        Gtk::Image legend_1_image;
        Gtk::Label legend_1_label;
        Gtk::Image legend_2_image;
        Gtk::Label legend_2_label;
        Gtk::Image legend_3_image;
        Gtk::Label legend_3_label;
        Gtk::Image legend_4_image;
        Gtk::Label legend_4_label;
        Gtk::Image legend_5_image;
        Gtk::Label legend_5_label;
        Gtk::Image legend_6_image;
        Gtk::Label legend_6_label;

        
        //Adjustement for spin button
		//Gtk::Adjustment adjust_spin_button;
		// *gtk_adjustment_new( gfloat 0, gfloat 0, gfloat 100, gfloat 1, gfloat 1, gfloat page_size );

    


};


#endif