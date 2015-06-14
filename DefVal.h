//**************************************************************************** 
// 
// 								    DefVal 
// 
//**************************************************************************** 
#ifndef __DefVal_H__ 
#define __DefVal_H__ 

// =========================================================================== 
// 								  Libraries 
// =========================================================================== 
#include <cstdio> 
#include <cstdlib> 
#include <string>

using std::string;

// =========================================================================== 
// 							  Struct declaration 
// =========================================================================== 
namespace DefVal {
	const unsigned int WINDOW_WIDTH = 800;
	const unsigned int WINDOW_HEIGHT = 500;
	const unsigned int WINDOW_BORDER_WIDTH = 10;
	const unsigned int WIDGETS_MARGIN_SIZE = 5;
	const unsigned int GENERATION_NUMBER_MAX = 50;
	const unsigned int HOST_NUMBER_MAX = 100;
	const unsigned int PARASITE_NUMBER_MAX = 20;
	const unsigned int PIC_WIDTH = 800;
	const unsigned int PIC_HEIGHT = 500;
	const unsigned int HOST_COMBOBOX_WRAP_WIDTH = 1;
	const int N_TRIANGLES_HOST = 30;
	const int N_TRIANGLES_PARASITE = 20;
	const int HOST_WIDTH = 20; // For max width. To be given as a PERCENTAGE of the PIC_WIDTH. Here 10%
	const int HOST_HEIGHT = 95; // PERCENTAGE of PIC_HEIGHT
	const int PARASITE_WIDTH = 12; // PERCENTAGE
	const int PARASITE_HEIGHT = 90; // PERCENTAGE
	const unsigned int NB_HOSTS = 75;
	
	const double FECONDITY_COEFF = 715044.3; 
	const unsigned int HOST_NUMBER_DEFAULT = 15;
	const unsigned int PARASITE_NUMBER_DEFAULT = 10;

	const string BUTTON1_LABEL = "Hummm, I like it when you click me!";
	const string APP_NAME = "Coevolution Model";
	const string ICON = "icon.png";
	
	const string START_BUTTON_LABEL = "Start";
	const string GENERATION_NUMBER_LABEL_TEXT = "Number of generations:";
	const string HOST_LABEL_TEXT = "Host:";
	const string HOST_NUMBER_LABEL_TEXT = "Number of hosts:";
	const string PARASITE_NUMBER_LABEL_TEXT = "Number of parasites per host:";
	const string STATISTICS_LABEL_TEXT = "Statistics:\tFitness:\tFecondity:";
	const string HOST_COMBOBOX_TITLE = "Choose Host";
	const string DISPLAY_IMAGE_FILE_NAME = "host_2.ppm";
	const string PIC_FORMAT = ".ppm";

	const string LEGEND_1_IMAGE_FILE_NAME = "legend_1.ppm";
	const string LEGEND_1_LABEL = "Environment";
	const string LEGEND_2_IMAGE_FILE_NAME = "legend_2.ppm";
	const string LEGEND_2_LABEL = "Host";
	const string LEGEND_3_IMAGE_FILE_NAME = "legend_3.ppm";
	const string LEGEND_3_LABEL = "Parasite";
	const string LEGEND_4_IMAGE_FILE_NAME = "legend_4.ppm";
	const string LEGEND_4_LABEL = "Environment, Host";
	const string LEGEND_5_IMAGE_FILE_NAME = "legend_5.ppm";
	const string LEGEND_5_LABEL = "Host, Parasite";
	const string LEGEND_6_IMAGE_FILE_NAME = "legend_6.ppm";
	const string LEGEND_6_LABEL = "Environment, Host, Parasite";
	const unsigned int LEGEND_WIDGETS_MARGIN_SIZE = 2;

	const unsigned int MAX_VAL_PICTURE= 255;
}

#endif // __DefVal_H__