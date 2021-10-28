#include "View.h"

void View::printBorder(char fillChar, int width) 
{
	std::cout << std::setfill(fillChar) << std::setw(width) << "" << std::endl;
}

void View::printField(std::string t_fieldName)
{
	std::cout << t_fieldName << ": ";
}

void View::printValue(double t_value, VALUE_TYPE t_type) 
{
	switch (t_type)
	{
		case CURRENCY:
			// Display as currency
			std::cout << std::showbase << std::put_money(t_value * 100) << std::flush;
			break;
		case PERCENT:
			// Display as percentage
			std::cout << "%" << std::setprecision(2) << std::fixed << t_value << std::flush;
			break;
		default:
			// Display basic numerical value
			std::cout << std::setprecision(0) << std::fixed << t_value << std::flush;
			break;
	}
}

void View::printHeading(std::string t_headingText, char t_borderChar, int t_width)
{
	printBorder(t_borderChar, t_width);
	std::cout << getCenteredText(t_headingText, t_width) << std::endl;
	printBorder(t_borderChar, t_width);
} 

std::string View::getCenteredText(std::string t_text, int t_width)
{
	// Calculate available space after text is inputted and add 1/2 that to each side to center text
	int availableSpace = t_width - t_text.length();
	int paddingSpace = availableSpace / 2;

	for (int i = 0; i < paddingSpace; i++) {
		t_text = " " + t_text + " ";
	}

	return t_text;
}

void View::printCompletedForm(std::vector<double> t_inputValues)
{
	std::vector<std::string> formFields = {INVESTMENT_AMOUNT, MONTHLY_DEPOSIT, ANNUAL_INTEREST, NUM_YEARS};

	system("CLS");
	printHeading(DATA_INPUT, '*', INPUT_WIDTH);
	
	// Iterate through each form field to rerender form and display user's choices for each field
	// If field is interest or currency field, add appropriate % or $ prefix.
	for (unsigned int i = 0; i < formFields.size(); i++) {
		printField(formFields.at(i));

		if (formFields.at(i) == ANNUAL_INTEREST) {
			printValue(t_inputValues.at(i), PERCENT);
		}
		
		else if (formFields.at(i) == NUM_YEARS) {
			printValue(t_inputValues.at(i));
		}

		else {
			printValue(t_inputValues.at(i), CURRENCY);
		}

		std::cout << std::endl;
	}
}

void View::printThreeColumnRow(std::string t_col1, std::string t_col2, std::string t_col3)
{
	int rowWidth = OUTPUT_WIDTH / 3;

	// Display organized string data in 3 column row
	std::cout << std::setfill(' ') << std::left
		 << std::setw(rowWidth) << t_col1
		 << std::setw(rowWidth) << t_col2
		 << std::setw(rowWidth) << t_col3
		 << std::endl;
}

void View::printThreeColumnRow(double t_col1, double t_col2, double t_col3)
{
	int rowWidth = OUTPUT_WIDTH / 3;

	// Display organized numerical data in 3 column row
	// Using calculation in put_money to correctly render currency values
	std::cout << std::setfill(' ') << std::left
		<< std::setw(rowWidth) << std::setprecision(0) << t_col1
		<< std::setw(rowWidth) << std::showbase << std::put_money(t_col2 * 100)
		<< std::setw(rowWidth) << std::showbase << std::put_money(t_col3 * 100)
		<< std::endl;
}

void View::printYearResults(OutputModel t_output, std::string t_heading)
{
	// Clear Console and Print Table Headings
	system("CLS");
	printHeading(t_heading, '=', OUTPUT_WIDTH);
	printThreeColumnRow(YEAR, YEAR_END_BALANCE, YEAR_END_INTEREST);
	printBorder('-', OUTPUT_WIDTH);

	// set temporary vectors from output model for iteration
	std::vector<double> yearEndBalances = t_output.getYearEndbBalances();
	std::vector<double> yearEndInterest = t_output.getYearlyEarnedInterest();

	// iterate through vectors and display values for each year
	for (unsigned int i = 0; i < t_output.getNumberOfYears(); i++) {
		int currentYear = i + 1;
		printThreeColumnRow(currentYear, yearEndBalances.at(i), yearEndInterest.at(i));
	}
}

void View::waitForInput() 
{
	std::cout << "\n" << CONTINUE_PROMPT << std::endl;
	_getch();
}