#include <iostream>
#include <iomanip>
#include <string>
#include "InvestmentMoney.cpp"
using namespace std;


void FormattedDisplayWithout() {  //Displays header for the static report with no monthly deposits
	cout << string(80, '_') << endl;
	cout << "      Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << string(80, '_') << endl;
	cout << "Year" << "                   " << "Year End Balance" << "        " << "Year End Earned Interest" << endl;
	cout << string(80, '_') << endl;
}
void FormattedDisplayWith() {  //Displays header for the static report with monthly deposits
	cout << string(80, '_') << endl;
	cout << "      Balance and Interest With Additional Monthly Deposits" << endl;
	cout << string(80, '_') << endl;
	cout << "Year" << "                   " << "Year End Balance" << "        " << "Year End Earned Interest" << endl;
	cout << string(80, '_') << endl;
}
 
int main(){
	InvestmentMoney userInvestment;     //Creating users investment object
	InvestmentMoney baseCaseInvestment; //Creating base case investment object
	int investment;
	int deposit;
	int interest;
	int years;
	char key;
	char loopKey = 'y';
	

	
	while (loopKey == 'y') {


		//Get information from user
		cout << "What is your initial investment amount?(ex. 1000) ";
		while (!(cin >> investment) || investment < 0 || investment > 99999999) {  //Input validation if cin meets requirements of int && 0 < int < 9999999
			cout << "enter valid input" << endl;
			cin.clear();
			cin.ignore(123, '\n');

		}
		userInvestment.SetUserInvestment(investment);
		cout << endl;

		cout << "What is your monthly deposit amount?(ex. 50) ";
		while (!(cin >> deposit) || deposit < 0 || deposit > 99999999) {  //Input validation if cin meets requirements of int && 0 < int < 9999999
			cout << "enter valid input" << endl;
			cin.clear();
			cin.ignore(123, '\n');

		}
		userInvestment.SetMonthlyDeposit(deposit);
		cout << endl;

		cout << "At what interest rate?(ex. 5 = 5%) ";
		while (!(cin >> interest) || interest < 0 || interest > 100) {  //Input validation if cin meets requirements of int && 0 < int < 100
			cout << "enter valid input" << endl;
			cin.clear();
			cin.ignore(123, '\n');

		}
		userInvestment.SetInterestRate(interest);
		cout << endl;

		cout << "For how many years?(ex. 5) ";
		while (!(cin >> years) || years <= 0 || years > 100) {  //Input validation if cin meets requirements of int && 0 < int < 100
			cout << "enter valid input" << endl;
			cin.clear();
			cin.ignore(123, '\n');

		}
		userInvestment.SetNumberYears(years);
		cout << endl;

		userInvestment.DisplayDataInput(); //Display the formatted user inputted information
		cout << "Press any key to continue. . . ";
		cin >> key;
		cout << endl;



		//Displays the base case information and the users case information
		FormattedDisplayWithout();
		baseCaseInvestment.SetUserInvestment(userInvestment.GetUserInvestment());
		baseCaseInvestment.SetInterestRate(userInvestment.GetInterestRate());
		baseCaseInvestment.SetNumberYears(userInvestment.GetNumberYears());
		baseCaseInvestment.DisplayBalanceWithInterest();
		FormattedDisplayWith();
		userInvestment.DisplayBalanceWithInterest();
		cout << endl;
		
		cout << "To exit press q. To continue press any key." << endl;
		cin >> loopKey;
		if (loopKey == 'q') {
			loopKey = 'q';
		}
		else {
			loopKey = 'y';
		}
	}
	
	
	return 0;
}