#include "Controller.h"

double Controller::getInputValue() 
{
	std::string input;
	double inputConverted;

	std::cin >> input;

	try
	{
		// Cast input string to double
		inputConverted = stod(input); 

		// Throw exception for values < 0
		if (inputConverted < 0) {
			throw new std::out_of_range(view.INVALID_ENTRY_PROMPT);
		}
	}

	catch (const std::exception&)
	{
		// Handle any exceptions including invalid characters
		// Recursively call getInputValue to recieve valid entry
		std::cout << view.INVALID_ENTRY_PROMPT << std::endl;
		return getInputValue();
	}

	return inputConverted;
}

void Controller::fetchFormData(InputModel& t_model)
{
	view.printHeading(view.DATA_INPUT, '*', view.INPUT_WIDTH);

	// Print initial investment field get data from user and store in input model class
	view.printField(view.INVESTMENT_AMOUNT);
	std::cout << "$" << std::flush;
	t_model.setInitialInvestment(getInputValue());

	// Print monthly deposit field get data from user and store in input model class
	view.printField(view.MONTHLY_DEPOSIT);
	std::cout << "$" << std::flush;
	t_model.setMonthlyDeposit(getInputValue());

	// Print annual interest field get data from user and store in input model class
	view.printField(view.ANNUAL_INTEREST);
	std::cout << "%" << std::flush;
	t_model.setAnnualInterestRate(getInputValue());

	// Print number of years field get data from user and store in input model class
	view.printField(view.NUM_YEARS);
	t_model.setNumberOfYears(getInputValue());

	t_model.setInputValues();
};

bool Controller::shouldContinue() 
{
	system("CLS");

	// Prompt User for character niput
	std::cout << view.NEW_FORM_PROMPT << std::endl;
	std::cout << view.ENTER_CHAR_PROMPT << std::flush;

	char choice = _getch();
	
	// If y or Y, clear screen and continue app
	if (choice == 'y' || choice == 'Y') {
		system("CLS");
		return true;
	}

	// If q or Q, clear screen and quit app
	else if (choice == 'q' || choice == 'Q') {
		system("CLS");
		return false;
	}

	else {
		// Any other entry is invalid and recursively call function until valid input is provided
		std::cout << view.INVALID_ENTRY_PROMPT;
		shouldContinue();
	}
}


void Controller::init() 
{
	// Set cout locale to correctly display currency from put_money
	std::cout.imbue(std::locale("en_US.UTF-8"));

	do {
		// Render Form
		InputModel inputData;
		fetchFormData(inputData);

		// Display User-submitted values in Form.
		view.printCompletedForm(inputData.getInputValues());
		view.waitForInput();

		// Instantiate Output model class and render results
		OutputModel outputData(inputData);
		view.printYearResults(outputData, view.OUTPUT_WITH_ADDITIONAL);
		view.waitForInput();

		// Instantiate Output model class and render results
		OutputModel outputDataNoDeposits(
			inputData.getNumberOfYears(), 
			inputData.getInitialInvestment(), 
			0, 
			inputData.getAnnualInterestRate()
		);

		view.printYearResults(outputDataNoDeposits, view.OUTPUT_WITHOUT_ADDITIONAL);
		view.waitForInput();
	} 
	while (shouldContinue());
}