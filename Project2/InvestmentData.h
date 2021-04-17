#pragma once
#ifndef PROJECT2_INVESTMENTDATA_H_
#define PROJECT2_INVESTMENTDATA_H_
#endif // !PROJECT2_INVESTMENTDATA_H_


class InvestmentData {
	public:
		void setInitialInvestment(double t_initialInvestment);
		void setMonthlyDeposit(double t_monthlyDeposit);
		void setAnnualInterest(double t_annualInterest);
		void setNumOfYears(int t_years);
		void setTotalWithDeposits(double t_amount);
		void setTotalWithoutDeposits(double t_amount);

		double getInitialInvestment() { return m_initialInvestment; }
		double getMonthlyDeposit() { return m_monthlyDeposit; }
		double getAnnualInterest() { return m_annualInterest; }
		int getNumOfYears() { return m_numOfYears; }
		double getTotalWithDeposits();
		double getTotalWithoutDeposits();

		double calcInterestWithDeposits();
		double calcInterestWithoutDeposits();
		

	private:
		double m_initialInvestment = 0.0;
		double m_monthlyDeposit = 0.0;
		double m_annualInterest = 0.0;
		int m_numOfYears = 0;
		double m_totalWithDeposits = 0.0;
		double m_totalWithoutDeposits = 0.0;
		
};