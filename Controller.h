#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <conio.h>

#include "InputModel.h"
#include "OutputModel.h"
#include "View.h"

/******************************************************************************
 *							- Controller Class -
 *
 *		Handles dispatching actions and updating view or data model classes.
 * 
 *		Loosely following MVC design pattern, model and view classes are unaware
 *      of each other and controller handles managing both classes: providing
 *		view class with data to render and updating model data.
 *******************************************************************************/
class Controller 
{
private:
	View view;

public:
	/** Fetch User Input From Console and sanitize value before returning casted double value 
	* @return converted input data
	*/
	double getInputValue();
	
	/** Render form and fetch values from user for each field
	*	Update inputModel with retrieved data
	*/
	void fetchFormData(InputModel& t_model);

	/** Inititalize Application */
	void init();

	/** Prompt User to continue running application or quit*/
	bool shouldContinue();
};

#endif