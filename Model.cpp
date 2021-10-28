#include "Model.h"

/*************************************************
 *				Getters & Setters                *
 *************************************************/

double Model::getNumberOfYears()
{
	return m_numberOfYears;
};

void Model::setNumberOfYears(int t_numberOfYears)
{
	m_numberOfYears = t_numberOfYears;
};

/*************************************************
 *				Calculation Functions            *
 *************************************************/

double Model::calculateInterestAmount(double t_openingAmt, double t_depositedAmt, double t_annualInterestRate)
{
	return (t_openingAmt + t_depositedAmt) * ((t_annualInterestRate / 100) / 12);
};

double Model::calculateSum(double value1, double value2)
{
	return value1 + value2;
};

int Model::calculateTotalMonths(int t_numberOfYears) {
	return t_numberOfYears * MONTHS_PER_YEAR;
}