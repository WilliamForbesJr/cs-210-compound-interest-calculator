#pragma once

#ifndef INPUT_MODEL_H
#define INPUT_MODEL_H

#include <vector>

#include "Model.h"

/******************************************************************************
 *							- Input Class -
 *
 *	This data model handles all data logic around initial user input data.
 *  This class purely handles getting and setting data derived from user input.
 * 
 *******************************************************************************/
class InputModel : public Model
{
private:

	/*************************************************
	 *				Private Data Members             *
	 *************************************************/
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterestRate;
	double m_numberOfYears;

	std::vector<double> m_inputValues;

public:

	/*************************************************
	 *				Getters & Setters                *
	 *************************************************/
	double getInitialInvestment();
	void setInitialInvestment(double t_initialInvestment);

	double getMonthlyDeposit();
	void setMonthlyDeposit(double t_monthlyDeposit);

	double getAnnualInterestRate();
	void setAnnualInterestRate(double t_annualInterestRate);

	double getNumberOfYears();
	void setNumberOfYears(int t_numberOfYears);

	void setInputValues();
	std::vector<double> getInputValues();
};

#endif