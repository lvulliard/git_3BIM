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
#include "Environment.h"
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
	env.saveGraphics();

	// Set the title
	set_title(DefVal::APP_NAME);
	// Set icon
	set_icon_from_file(DefVal::ICON);
	// Set window size
	resize(DefVal::WINDOW_WIDTH, DefVal::WINDOW_HEIGHT);
	// Window position
	set_position(Gtk::WIN_POS_CENTER);

	
	Main_table.resize(5,5); // Resize table
	add(Main_table); // Add table container


	// Attach host_label
	Main_table.attach(host_label,0,1,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	host_label.set_label(DefVal::HOST_LABEL_TEXT);

	// Attach host_combobox
	Main_table.attach(host_combobox,1,2,0,1, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	host_combobox.set_wrap_width(DefVal::HOST_COMBOBOX_WRAP_WIDTH);
	host_combobox.set_title(DefVal::HOST_COMBOBOX_TITLE);
	Fill_host_combobox();
	// Link the option chosen in the combobox to the display of a profile
	host_combobox.signal_changed().connect(sigc::mem_fun(*this, &Main_Window::change_central_pic));

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
	Main_table.attach(start_button,4,5,0,2, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	start_button.set_label(DefVal::START_BUTTON_LABEL);
	start_button.signal_clicked().connect(sigc::mem_fun(*this, &Main_Window::Start_button_clicked));

	// // Attach host_number_label
	// Main_table.attach(host_number_label,0,1,1,2, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	// host_number_label.set_label(DefVal::HOST_NUMBER_LABEL_TEXT);

	// // Attach host_number_spinbutton
	// Main_table.attach(host_number_spinbutton,1,2,1,2, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	// host_number_spinbutton.set_numeric(TRUE);
	// host_number_spinbutton.set_wrap(FALSE);
	// host_number_spinbutton.set_range(1, DefVal::HOST_NUMBER_MAX);
	// host_number_spinbutton.set_value(DefVal::HOST_NUMBER_DEFAULT);
	// host_number_spinbutton.set_increments(1,10);
	// host_number_spinbutton.signal_value_changed().connect(sigc::mem_fun(*this, &Main_Window::host_number_spinbutton_changed));

	// // Attach parasite_number_label
	// Main_table.attach(parasite_number_label,2,3,1,2, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	// parasite_number_label.set_label(DefVal::PARASITE_NUMBER_LABEL_TEXT);

	// // Attach parasite_number_spinbutton
	// Main_table.attach(parasite_number_spinbutton,3,4,1,2, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	// parasite_number_spinbutton.set_numeric(TRUE);
	// parasite_number_spinbutton.set_wrap(FALSE);
	// parasite_number_spinbutton.set_range(0, DefVal::PARASITE_NUMBER_MAX);
	// parasite_number_spinbutton.set_value(DefVal::PARASITE_NUMBER_DEFAULT);
	// parasite_number_spinbutton.set_increments(1,10);
	// parasite_number_spinbutton.signal_value_changed().connect(sigc::mem_fun(*this, &Main_Window::parasite_number_spinbutton_changed));

	// Attach display_image
	Main_table.attach(display_image,0,5,2,3, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	display_image.set(DefVal::DISPLAY_IMAGE_FILE_NAME);

	// Attach statistics_label
	Main_table.attach(statistics_label,0,5,4,5, Gtk::FILL, Gtk::FILL,DefVal::WIDGETS_MARGIN_SIZE,DefVal::WIDGETS_MARGIN_SIZE);
	statistics_label.set_label(DefVal::STATISTICS_LABEL_TEXT);

	// Attach legend_table
	Main_table.attach(legend_table,0,5,3,4, Gtk::FILL, Gtk::FILL,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_table.resize(1,12); // Resize table
	add(legend_table);
	// Attach legend_1_image
	legend_table.attach(legend_1_image,0,1,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_1_image.set(DefVal::LEGEND_1_IMAGE_FILE_NAME);
	// Attach legend_1_label
	legend_table.attach(legend_1_label,1,2,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_1_label.set_label(DefVal::LEGEND_1_LABEL);
	// Attach legend_2_image
	legend_table.attach(legend_2_image,2,3,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_2_image.set(DefVal::LEGEND_2_IMAGE_FILE_NAME);
	// Attach legend_2_label
	legend_table.attach(legend_2_label,3,4,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_2_label.set_label(DefVal::LEGEND_2_LABEL);
	// Attach legend_3_image
	legend_table.attach(legend_3_image,4,5,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_3_image.set(DefVal::LEGEND_3_IMAGE_FILE_NAME);
	// Attach legend_3_label
	legend_table.attach(legend_3_label,5,6,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_3_label.set_label(DefVal::LEGEND_3_LABEL);
	// Attach legend_4_image
	legend_table.attach(legend_4_image,6,7,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_4_image.set(DefVal::LEGEND_4_IMAGE_FILE_NAME);
	// Attach legend_4_label
	legend_table.attach(legend_4_label,7,8,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_4_label.set_label(DefVal::LEGEND_4_LABEL);
	// Attach legend_5_image
	legend_table.attach(legend_5_image,8,9,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_5_image.set(DefVal::LEGEND_5_IMAGE_FILE_NAME);
	// Attach legend_5_label
	legend_table.attach(legend_5_label,9,10,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_5_label.set_label(DefVal::LEGEND_5_LABEL);
	// Attach legend_3_image
	legend_table.attach(legend_6_image,10,11,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_6_image.set(DefVal::LEGEND_6_IMAGE_FILE_NAME);
	// Attach legend_6_label
	legend_table.attach(legend_6_label,11,12,0,1, Gtk::FILL | Gtk::EXPAND, Gtk::FILL | Gtk::EXPAND,DefVal::LEGEND_WIDGETS_MARGIN_SIZE,DefVal::LEGEND_WIDGETS_MARGIN_SIZE);
	legend_6_label.set_label(DefVal::LEGEND_6_LABEL);

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
  	for (int i = 0; i < DefVal::NB_HOSTS; ++i)
  	{
  		char name[100];
    	sprintf(name,"host_%d", i);
    	host_combobox.append(name);
 	}	
	host_combobox.set_active_text("host_0");
}

void Main_Window::change_central_pic(void)
{
	string text2 = host_combobox.get_active_text(); 
	string f_name = text2 + DefVal::PIC_FORMAT;
	display_image.set(f_name);
	int index = text2[6];
	//printf("Fecondity of host[%d] = %lf\n", index, env.hosts_fecondity[index]);

	//statistics_label.set_label("Statistics of Host :\tFitness:\tFecondity:");
}

void Main_Window::Start_button_clicked(void)
{
	int n;
	n = generation_number_spinbutton.get_value();
	printf("Uuuuuuuh: %d generations\n",n);

	for(int i = 0; i < n; i++)
	{
		env.newGeneration();
		env.mutation();
	}
	
	env.saveGraphics();

	string text2 = host_combobox.get_active_text(); 
	string f_name = text2 + DefVal::PIC_FORMAT;
	display_image.set(f_name);


}

// void Main_Window::host_number_spinbutton_changed(void)
// {
// 	int n;
// 	n = host_number_spinbutton.get_value();
// 	printf("Uuuuuuuh: %d hosts\n",n);
// }

// void Main_Window::parasite_number_spinbutton_changed(void)
// {
// 	int n;
// 	n = parasite_number_spinbutton.get_value();
// 	printf("Uuuuuuuh: %d parasites\n",n);
// }


