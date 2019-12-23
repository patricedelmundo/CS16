//
//  main.cpp
//  stddev
//
//  Created by Sherlock on 11/3/16.
//  Copyright © 2016 Sherlock. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cmath>
#include <cctype>

using namespace std;

void calcDeviation(ifstream& input_file, string myFile, double average);
double calcAverage(ifstream& input_file, string myFile);

int main() {
    
    ifstream input_file;
    string myFile;
    
    cout << "Enter filename:\n";
    cin >> myFile;
    
    if (input_file.fail()) {
        cerr << "Unable to open the input file\n";
        exit(1);
    }
    double average = calcAverage(input_file,myFile);
    calcDeviation(input_file, myFile, average);
    input_file.close();
    
    return 0;
}

double calcAverage(ifstream& input_file, string myFile)
{
    double sum = 0;
    int count = 0;
    double number;
    double average;
    input_file.open(myFile);
    while (input_file >> number) {
        sum += number;
        count++;
    }

    average = sum / count;
    input_file.close();
    return average;
    
    
}
void calcDeviation(ifstream& input_file, string myFile, double average)
{
    
    int count = 0;
    double number;
    double variance = 0;
    double stdDeviation;
    input_file.open(myFile);
    while (input_file >> number)
    {
        variance += pow((number - average),2);
        count++;
    }
    input_file.close();
    stdDeviation = sqrt(variance/(count -1));
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "The standard deviation is " << stdDeviation << endl;
}
