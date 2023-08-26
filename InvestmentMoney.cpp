#include "InvestmentMoney.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Constructor
InvestmentMoney::InvestmentMoney() {
	m_initialInvestment = 1;
	m_monthlyDeposit = 0;
	m_interestRate = 5;
	m_numberOfYears = 5;
}
//Sets the users initial investment
void InvestmentMoney::SetUserInvestment(int t_initialMoney) {
	m_initialInvestment = t_initialMoney;
}
int InvestmentMoney::GetUserInvestment() const {
	return m_initialInvestment;
}
//Sets the users monthly deposit
void InvestmentMoney::SetMonthlyDeposit(int t_deposit) {
	m_monthlyDeposit = t_deposit;
}
int InvestmentMoney::GetMonthlyDeposit() const {
	return m_monthlyDeposit;
}
//Sets the users interest rate
void InvestmentMoney::SetInterestRate(int t_interest) {
	m_interestRate = t_interest;
}
int InvestmentMoney::GetInterestRate() const {
	return m_interestRate;
}
//Sets the amount of years the money will be growing
void InvestmentMoney::SetNumberYears(int t_years) {
	m_numberOfYears = t_years;
}
int InvestmentMoney::GetNumberYears() const {
	return m_numberOfYears;
}

//This method displays the user inputted financial criteria
void InvestmentMoney::DisplayDataInput() {
	cout << string(34, '*') << endl;
	cout << string(11, '*') << " Data Input " << string(11, '*') << endl;
	cout << "Initial Investment Amount: " << "$" << m_initialInvestment << ".00" << endl;
	cout << "Monthly Deposit: " << "$" << m_monthlyDeposit << ".00" << endl;
	cout << "Annual Interest: " << "%" << m_interestRate << endl;
	cout << "Number of years: " << m_numberOfYears << endl;;
}
//Monthly calculation of interest to be used in DisplayBalanceWithInterest method
double InvestmentMoney::CalculateInterest(int initial, int monthly, int interest) {
	double total;
	total = ((initial / 1.0) + monthly) * ((interest / 100.0) / 12.0);
	return total;

}

//Year end balance and interest calculation
void InvestmentMoney::DisplayBalanceWithInterest() {
	double initial = m_initialInvestment;
	int monthly = m_monthlyDeposit;
	int interest = m_interestRate;
	double monthlyTotal = 0;

	for (int i = 1; i <= m_numberOfYears * 12; i++) {
		monthlyTotal += CalculateInterest(initial, monthly, interest);
		initial = (CalculateInterest(initial, monthly, interest) + initial + monthly);
		if (i % 12 == 0) {
			cout << setw(15) << left << (i / 12);
			cout << setw(15) << right << "$";
			cout << setw(8) << right << fixed << setprecision(2) << initial;
			cout << setw(15) << right << "$";
			cout << setw(8) << right << fixed << setprecision(2) << monthlyTotal << endl;
			cout << endl;
			monthlyTotal = 0;
		}
	}
}
