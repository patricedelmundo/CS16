//
//  change.cpp
//  change
//
//  Created by Sherlock on 10/27/16.
//  Copyright © 2016 Sherlock. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void compute_coins(int coin_value, int& num, int& amount_left);

int main()
{

    do{
        
    int amount =0;
    int quarters = 0;
    int dimes = 0;
    int pennies = 0;
    int change = 0;
        
    cout << "Enter number of cents (or zero to quit):\n";
    cin>>amount;
            
    change = amount;

    if (amount == 0){
        return 0;
    }
    
    if(amount != 0){
        cin.get();
    }

    compute_coins (25, quarters, amount);
    compute_coins (10, dimes, amount);
    compute_coins (01, pennies, amount);
    
    cout<<change
        <<" cents can be given as ";

    if (quarters == 1){
        cout<<quarters
            <<" quarter";
        
        if ((dimes && pennies) == 0){
            cout<<".";
        }
        
        else
            cout<<", ";
    }

    if (quarters > 1){
        cout<<quarters
            <<" quarters";
        
        if ((dimes && pennies) == 0){
            cout<<".";
        }
        
        else
            cout<<", ";
    }

    if (dimes == 1){
        cout<<dimes
            <<" dime";
        
        if (pennies ==0){
            cout<<".";
        }
        
        else
            cout<<", ";
    }

    if (dimes > 1) {
        cout<<dimes
            <<" dimes";
        
        if (pennies == 0) {
            cout<<".";
        }
        
        else{
            cout<<", ";
        }
    }

    if (pennies == 1){
        cout<<pennies
            <<" penny.\n";
    }
    if (pennies > 1){
        cout<<pennies
            <<" pennies.\n";
    }
    } while (`amount > 0);
}

void compute_coins(int coinValue, int& number, int& amountLeft)
{
    number = amountLeft/ coinValue;
    amountLeft = amountLeft - (coinValue*number);
}
