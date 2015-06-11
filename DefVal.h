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
	const unsigned int WINDOW_HEIGHT = 600;
	const unsigned int WINDOW_BORDER_WIDTH = 10;
	const unsigned int WIDGETS_MARGIN_SIZE = 10;
	const unsigned int GENERATION_NUMBER_MAX = 100;

	const string BUTTON1_LABEL = "Hummm, I like it when you click me!";
	const string APP_NAME = "Coevolution Model";
	const string ICON = "icon.png";
	
	const string START_BUTTON_LABEL = "Start";
	const string GENERATION_NUMBER_LABEL_TEXT = "Number of generations:";
	const string HOST_LABEL_TEXT = "Host:";
	const string STATISTICS_LABEL_TEXT = "Statistics: :'(";
	const unsigned int HOST_COMBOBOX_WRAP_WIDTH = 1;
	const string HOST_COMBOBOX_TITLE = "Choose Host";
	const string DISPLAY_IMAGE_FILE_NAME = "host_2.jpg";
	const string PIC_FORMAT = ".jpg";
}

#endif // __DefVal_H__