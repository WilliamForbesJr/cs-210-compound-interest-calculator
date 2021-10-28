#pragma once

#ifndef OUTPUTMODEL_H
#define OUTPUTMODEL_H

#include <vector>

#include "InputModel.h"
#include "Model.h"

/******************************************************************************
 *							- OutputModel Class - 
 * 
 *	This data model handles all data logic around yearly investment output data.
 *  We can either provide the input model into the constructor to calculate values
 *  purely frmo derived input model. Or we can provide custom fields to calculate
 *  any output data we choose.
 *******************************************************************************/
class OutputModel: public Model
{
	int m_totalMonths;

	// Year end Interest and balance arrays from calculated input values
	std::vector<double> m_yearlyEarnedInterest;
	std::vector<double> m_yearEndBalances;

public:

	/*************************************************
	 *					Constructors	             *
	 *************************************************/

	OutputModel(InputModel t_inputModel);

	/* Overloaded constructor to take custom params instead of input model object. 
	 * Used to create custom outputs such as calculations with no monthly deposit.
	*/
	OutputModel(int t_numberOfYears, double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate);


	/*************************************************
	 *				Getters & Setters                *
	 *************************************************/

	std::vector<double> getYearEndbBalances();
	void updateYearEndBalances(double t_yearEndBalance);

	std::vector<double> getYearlyEarnedInterest();
	void updateYearlyEarnedInterest(double t_yearEarnedInterest);

	/**
	* Iterate through 12 months/year for x amount of years, add monthly investment and compound interest.
	* Every 12 months, set year end interest and balance into output class vectors
	*/
	void calculateCompoundGains(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate);
};

#endif