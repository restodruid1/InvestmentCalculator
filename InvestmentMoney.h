#pragma once
#ifndef INVESTMENTMONEY_H
#define INVESTMENTMONEY_H

class InvestmentMoney {
	public:
		InvestmentMoney();
		void SetUserInvestment(int t_initialMoney);
		int GetUserInvestment() const;
		void SetMonthlyDeposit(int t_deposit);
		int GetMonthlyDeposit() const;
		void SetInterestRate(int t_interest);
		int GetInterestRate() const;
		void SetNumberYears(int t_years);
		int GetNumberYears() const;
		void DisplayDataInput();
		void DisplayBalanceWithInterest();
		double CalculateInterest(int initial, int monthly, int interest);

	private:
		int m_initialInvestment;
		int m_monthlyDeposit;
		int m_interestRate;
		int m_numberOfYears;
};

#endif
