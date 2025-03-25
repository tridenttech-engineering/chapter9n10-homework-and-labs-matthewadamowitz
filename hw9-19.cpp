
//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Matthew Adamowitz> on <3/24/25>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
double getPayment(int, double, int);

int main()
{
    //declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);    //assign values to calculate payments
    
    //display payments
    cout << fixed << setprecision(2) << endl; 

    if (creditPayment == -1 || dealerPayment == -1)
    {
        cout << "Error: Division by zero encountered in payment calculation.\n";
    }
    else
    {
        cout << "Credit union monthly payment: $" << creditPayment << endl;
        cout << "Dealer monthly payment: $" << dealerPayment << endl;

        //calculate and display total payments
        double totalCredit = creditPayment * (term *12); 
        double totalDealer = dealerPayment * (term * 12);

        cout << "Total paid through credit union: $" << totalCredit << endl;
        cout << "Total paid through dealer: $" << totalDealer << endl;
    }
    return 0;

}//end of main function

//function to calculate monthly payments
double getPayment(int prin, double monthRate, int months)
{
    if(monthRate == 0)
    {
        return static_cast<double>(prin) / months; 
    }

    double denominator = pow(1 +monthRate, months) -1; 
    if (denominator == 0)
    {
        return -1;
    }

    return (prin * monthRate * pow(1 + monthRate, months)) / denominator;
}