#include "OutputModel.h"

/*************************************************
 *					Constructors	             *
 *************************************************/

OutputModel::OutputModel(InputModel t_inputModel) 
{
	m_numberOfYears = t_inputModel.getNumberOfYears();
	m_totalMonths = calculateTotalMonths(m_numberOfYears);
	calculateCompoundGains(t_inputModel.getInitialInvestment(), t_inputModel.getMonthlyDeposit(), t_inputModel.getAnnualInterestRate());
}

OutputModel::OutputModel(int t_numberOfYears, double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate) 
{
	m_numberOfYears = t_numberOfYears;
	m_totalMonths = calculateTotalMonths(t_numberOfYears);
	calculateCompoundGains(t_initialInvestment, t_monthlyDeposit, t_annualInterestRate);
};

/*************************************************
 *				Getters & Setters                *
 *************************************************/

std::vector<double> OutputModel::getYearEndbBalances()
{
	return m_yearEndBalances;
}

void OutputModel::updateYearEndBalances(double t_yearEndBalance)
{
	m_yearEndBalances.push_back(t_yearEndBalance);
}

std::vector<double> OutputModel::getYearlyEarnedInterest()
{
	return m_yearlyEarnedInterest;
}

void OutputModel::updateYearlyEarnedInterest(double t_yearEarnedInterest)
{
	m_yearlyEarnedInterest.push_back(t_yearEarnedInterest);
}

/*************************************************
 *				Calculation Functions            *
 *************************************************/

void OutputModel::calculateCompoundGains(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterestRate)
{
	// yearEndBalance and yearEndInterest are accumulators.
	// We start yearEndBalance with initial investment amount and yearEndInterest at 0 since
	// interest has yet to accrue on day 1.
	double yearEndBalance = t_initialInvestment;
	double yearEndInterest = 0;

	// iterate through total months to compound savings rates
	for (int i = 1; i <= m_totalMonths; i++) {
		// accumulate monthly totals for balance and interest
		double monthlyTotal = calculateSum(yearEndBalance, t_monthlyDeposit);
		double interest = calculateInterestAmount(yearEndBalance, t_monthlyDeposit, t_annualInterestRate);

		// Accumulate yearly values each month
		yearEndInterest += interest;
		yearEndBalance = calculateSum(monthlyTotal, interest);;

		// On month 12, we store end of year values into balance and interest vectors
		if (i % 12 == 0) {
			updateYearlyEarnedInterest(yearEndInterest);
			updateYearEndBalances(yearEndBalance);

			// reset interest gained to reflect yearly earned interest
			yearEndInterest = 0;
		}
	}
};