//  Created by Sherlock on 10/27/16.
//  Copyright © 2016 Sherlock. All rights reserved.

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void compute_coins(int coin_value, int& num, int& amount_left);

int main()

{
    int amount = 0;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;
    int change = 0;

    cout << "Enter number of cents (or zero to quit):\n";
    cin>>amount;
    
    change = amount;
    
    if (amount == 0){
        cin.get();
        cin.get();
        return 0;
    }
    
    if( amount < 1 || amount > 99){
        cout << " Error, Please enter value between 1 and 99 cents.\n";
    }
    
    compute_coins (25, quarters, amount);
    compute_coins (10, dimes, amount);
    compute_coins (05, nickels, amount);
    compute_coins (01, pennies, amount);
    
    cout<<change
    <<" cents can be given as ";
    
    if (quarters == 1){
        cout<<quarters
        <<" quarter, ";
    }
    
    if (quarters > 1){
        cout<<quarters
        <<" quarters, ";
    }
    
    if (dimes == 1){
        cout<<dimes
        <<" dime, ";
    }
    
    if (dimes > 1) {
        cout<<dimes
        <<" dimes, ";
    }
    
    if (pennies == 1){
        cout<<pennies
        <<" penny.\n";
    }
    if (pennies > 1){
        cout<<pennies
        <<" pennies.\n";
    }
    return 0;

void compute_coins(int coinValue, int& number, int& amountLeft)
{
    number = amountLeft/ coinValue;
    amountLeft = amountLeft - (coinValue*number);
}
