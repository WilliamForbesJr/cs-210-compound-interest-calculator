#pragma once

#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>

#include "OutputModel.h"

/******************************************************************************
 *							- View Class -
 *
 * Handles all rendering logic.
 * 
 * View class stores public constant text fields used as an abstraction layer to
 * cleanly handle outputted text and serve as a single point of updating string values.
 * 
 * View class also contains some helper functions to mutate data as well as
 * interpolate and cast integer values to string for display.
 *******************************************************************************/
class View 
{
public:
	// Input form width
	const int INPUT_WIDTH = 30;

	// output table width
	const int OUTPUT_WIDTH = 90;

	/** Enums used in function params to determine how numerical output is displayed */
	const enum VALUE_TYPE
	{
		NUMBER = 0,
		CURRENCY = 1,
		PERCENT = 2,
	};

	/*************************************************
	 *				Text Constant Values             *
	 *************************************************/

	/*------------------------------*
	 *			Input Text			*
	 *------------------------------*/
	const std::string INVESTMENT_AMOUNT	= "Initial Investment Amount";
	const std::string MONTHLY_DEPOSIT	= "Monthly Deposit";
	const std::string ANNUAL_INTEREST	= "Annual Interest";
	const std::string NUM_YEARS			= "Number of Years";
	const std::string DATA_INPUT		= "Data Input";

	/*------------------------------*
	 *			Output Text			*
	 *------------------------------*/
	const std::string OUTPUT_WITHOUT_ADDITIONAL	= "Balance and Interest Without Additional Monthly Deposits";
	const std::string OUTPUT_WITH_ADDITIONAL	= "Balance and Interest With Additional Monthly Deposits";
	const std::string YEAR						= "Year";
	const std::string YEAR_END_BALANCE			= "Year End Balance";
	const std::string YEAR_END_INTEREST			= "Year End Earned Interest";

	/*------------------------------*
	 *		User Prompt Text		*
	 *------------------------------*/
	const std::string CONTINUE_PROMPT		= "Press any key to continue . . .";
	const std::string NEW_FORM_PROMPT		= "\nEnter a new Form?\n";
	const std::string ENTER_CHAR_PROMPT		= "Press 'y' to continue or 'q' to quit...";
	const std::string INVALID_ENTRY_PROMPT	= "\nINVALID ENTRY.TRY AGAIN\n";


	/*************************************************
	 *				Printing Functions               *
	 *************************************************/

	/* Receive text value and width of line it will be rendered on and concatenate empty characters to center */
	std::string getCenteredText(std::string t_text, int t_width);

	/* Print border to console with selected fill character and width size */
	void printBorder(char fillChar, int width);

	/* Print Centered Heading with border from borderChar and inputted width */
	void printHeading(std::string t_headingText, char t_borderChar, int t_width);

	/* Print input form field */
	void printField(std::string t_fieldName);

	/* Print output value from inputform - Used to rerender inputted user data*/
	void printValue(double t_value, VALUE_TYPE t_type=NUMBER);

	/* Rerender form to include user-submitted values */
	void printCompletedForm(std::vector<double> t_inputValues);

	/* Print 3 column row used in table */
	void printThreeColumnRow(std::string t_col1, std::string t_col2, std::string t_col3);

	/* Overloaded 3 column row function to render interpolated currency and numerical data */
	void printThreeColumnRow(double t_col1, double t_col2, double t_col3);

	/* Iterate through each year provided from output model to display data with appropriate heading */
	void printYearResults(OutputModel t_output, std::string t_heading);
	
	/* Display output to user for continue prompt*/
	void waitForInput();
};

#endif