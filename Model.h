#pragma once

#ifndef MODEL_H
#define MODEL_H

/******************************************************************************
 *							- Model Class -
 *
 *	Generic Data model parent class.
 *	Handles common data and provides functions for  input/output children classes
 *******************************************************************************/
class Model 
{
protected:
	// number of years field shared between children
	double m_numberOfYears = 0;

	// months per year constant to avoid magic numbers
	const int MONTHS_PER_YEAR = 12;

public:

	/*************************************************
	 *				Getters & Setters                *
	 *************************************************/

	double getNumberOfYears();
	void setNumberOfYears(int t_numberOfYears);

	/*************************************************
	 *				Calculation Functions            *
	 *************************************************/

	/* Calculate monthly interest rates */
	double calculateInterestAmount(double t_openingAmt, double t_depositedAmt, double t_annualInterestRate);

	/* Simple addition function abstraction to more tightly control sum operations */
	double calculateSum(double value1, double value2);
	
	/* Calculate total months by taking number of years * months per year */
	int calculateTotalMonths(int t_numberOfYears);
};

#endif