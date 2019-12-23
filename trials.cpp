//
//  trials.cpp
//  hw03
//
//  Created by Sherlock on 10/4/16.
//  Copyright © 2016 Sherlock. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string username;
    int favorite_number;
    
    cout<<"Enter your favorite number";
    cin>>favorite_number;
    cout<<"Enter your name";
    cin>>username;

    cout<<"Hello "<<username<<" your favorite number is "<<favorite_number<<"!\n";

    
    favorite_number=(((favorite_number*5)*5)*5);
    cout<<"I took your number and multiplied it by 5 THREE times and the result was: "<<favorite_number<<"."<<endl;
    
    return 0;
}
