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

	const string BUTTON1_LABEL = "Hummm, I like it when you click me!";
	const string APP_NAME = "Coevolution model";
	const string ICON = "icon.png";
	
} 

#endif // __DefVal_H__