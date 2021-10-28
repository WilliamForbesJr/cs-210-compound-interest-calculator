#include "InputModel.h"

/******************************************************************************
 *							GETTERS AND SETTERS							   	  *
 ******************************************************************************/

/*---------------------------------------*
 *			Initial Investment			 *
 *---------------------------------------*/

double InputModel::getInitialInvestment() 
{
	return m_initialInvestment;
};

void InputModel::setInitialInvestment(double t_initialInvestment)
{
	m_initialInvestment = t_initialInvestment;
};

/*---------------------------------------*
 *			Monthly Deposit				 *
 *---------------------------------------*/

double InputModel::getMonthlyDeposit()
{
	return m_monthlyDeposit;
};

void InputModel::setMonthlyDeposit(double t_monthlyDeposit)
{
	m_monthlyDeposit = t_monthlyDeposit;
};

/*---------------------------------------*
 *			Annual Interest				 *
 *---------------------------------------*/

double InputModel::getAnnualInterestRate()
{
	return m_annualInterestRate;
};

void InputModel::setAnnualInterestRate(double t_annualInterestRate)
{
	m_annualInterestRate = t_annualInterestRate;
};

/*---------------------------------------*
 *			Number of Years				 *
 *---------------------------------------*/

double InputModel::getNumberOfYears()
{
	return m_numberOfYears;
};

void InputModel::setNumberOfYears(int t_numberOfYears)
{
	m_numberOfYears = t_numberOfYears;
};

/*---------------------------------------*
 *			Input Values Vector			 *
 *---------------------------------------*/

void InputModel::setInputValues()
{
	m_inputValues = {
		getInitialInvestment(),
		getMonthlyDeposit(),
		getAnnualInterestRate(),
		getNumberOfYears(),
	};
}

std::vector<double> InputModel::getInputValues()
{
	return m_inputValues;
}
