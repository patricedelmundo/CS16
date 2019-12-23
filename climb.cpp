//
//  climb.cpp
//  climb
//
//  Created by Sherlock on 11/13/16.
//  Copyright © 2016 Sherlock. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include<string>

using namespace std;
string removeSpace(string str);

//declaring the different sorting methods
int sort(char a[], int size, int& min);
int sortMax(char a[], int size, int& max);
int find_next_smallest(char a[], int x, int y, int& min);
int find_next_largest(char a[], int x, int y, int& max);

int main()
{
    char map[10][10];
    string input[10];
    char minArray[10], maxArray[10];
    int minPos[10], maxPos[10];
    int base, peak;
    cout << "Enter heights:" << endl;
    
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = '*';
        }
    }
    // getting input from user
    int k = 0;
    int n = 0;
    bool valid = true;
    while((valid==true) && k<10)
    {
        getline(cin, input[k]);
        if(input[k].length() == 0)
            valid = false;
        k++;
    }
    char minValue = map[0][0];
    int min, max;
    for (int i = 0; i < 10; i++)
    {
        string noSpace = removeSpace(input[i]);
        for (int j = 0; j < 10; j++)
        {
            map[i][j] = noSpace[j];
        }
        if (noSpace.length() == 0)
            break;
        //finds the smallest number and its array position
        minPos[i] = sort((map[i]), noSpace.length(), min);
        maxPos[i] = sortMax((map[i]), noSpace.length(), max);
        minArray[i] = char (min);
        maxArray[i] = char (max);
        n++;
    }
    int finalMin, finalMax;
    base = sort((minArray), n, finalMin);
    peak = sortMax((maxArray), n, finalMax);
    
    
    // Equation
    double run, rise, angle;
    run = sqrt(pow((base-peak),2) + pow((minPos[base]-maxPos[peak]),2));
    rise = (finalMax-48) - (finalMin-48);
    angle = atan(rise/run);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);
    cout << "The angle of the climb is " << angle << " radians." << endl;
    
    return 0;
}
//for removing spaces from strings
string removeSpace(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (isspace(str[i]))
            str.erase(str.begin() + i);
    }
    return str;
}

int sort(char a[], int size, int& min) {
    int value;
    
    for (int index = 0; index < size; index++)
    {
        int value = find_next_smallest(a, index, size, min);
        return value;
    }
    return 0;
}

int find_next_smallest(char a[], int start_index, int size, int& min) {
    
    min = int(a[start_index]);
    int index_of_min = start_index;
    
    for (int index = start_index;   index < size;   index++) {
        if (int (a[index]) < min) {
            min = (a[index]);
            index_of_min = index;
        }
    }
    return index_of_min;
}

int sortMax(char a[], int size, int& max)
{
    int value;
    
    for (int index = 0; index < size; index++)
    {
        int value = find_next_largest(a, index, size, max);
        return value;
    }
    return 0;
}

int find_next_largest(char a[], int start_index, int size, int& max)
{
    
    max = a[start_index];
    int index_of_max = start_index;
    
    for (int index = start_index;   index < size;   index++) {
        if (int (a[index]) > max)
        {
            max = a[index];
            index_of_max = index;
        }
    }
    return index_of_max;
}
