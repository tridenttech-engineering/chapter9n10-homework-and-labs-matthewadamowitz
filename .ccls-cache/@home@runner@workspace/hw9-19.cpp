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
    cout << "Credit union rate (as a decimal): ";
    cin >> creditRate;
    cout << "Dealer rate (as a decimal): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    int months = term * 12; 
    
    //call function to calculate payments
    creditPayment = getPayment(carPrice - rebate,
        creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice,
        dealerRate / 12, term * 12);

    //round payments to 2 decimal places
    creditPayment = round(creditPayment * 100) / 100;
    dealerPayment = round(dealerPayment * 100) / 100;
    
    //display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Total credit union payment: $" << (creditPayment * months) << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    cout << "Total dealer payment: $" << (dealerPayment * months) << endl;
    
    return 0;
    
}

//function definitions
double getPayment(int prin, double monthRate, int months)    
{    
    if (monthRate == 0) //prevetn division by zero 
        return -1; 

    double denominator = (1 - pow(1 + monthRate, -months));
    if (denominator == 0)
        return -1; 

    return prin * monthRate / denominator;
}