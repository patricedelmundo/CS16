//
//  main.cpp
//  operators
//
//  Created by Sherlock on 11/6/16.
//  Copyright © 2016 Sherlock. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
using namespace std;

string filename;

const void correct(ifstream& fin,ofstream& fout);
int main()
{
    ifstream fin;
    ofstream fout;
    cout << "Enter filename:\n";
    cin>> filename;
    fin.open( filename);
    
    if(fin.fail())
    {
        return 0;
    }
    
    fout.open("correctorig.txt");
    
    if(fout.fail())
    {
        return 0;
    }
    
    correct(fin,fout);
    
    fin.close();
    fout.close();
    
    return 0;
}

const void correct(ifstream& fin,ofstream& fout)
{
    char next;
    fin.get(next);
    while(!fin.eof())
    {
        if(next == 'c')
        {
            fin.get(next);
            if(next == 'i')
            {
                fin.get(next);
                if(next == 'n')
                {
                    fin >> next;
                    if(next == '<')
                    {
                        fin >> next;
                        if(next == '<')
                        {
                            fout << "cin >>";
                            fin.get(next);
                        }
                        else
                        {
                            fout << "cin >" << next;
                            fin.get(next);
                        }
                    }
                    else
                    {
                        fout << "cin " << next;
                        fin.get(next);
                    }
                }
                else
                {
                    fout << "ci" << next;
                    fin.get(next);
                }
            }
            else if(next == 'o')
            {
                fin.get(next);
                if(next == 'u')
                {
                    fin.get(next);
                    if(next == 't')
                    {
                        fin >> next;
                        if(next == '>')
                        {
                            fin.get(next);
                            if(next == '>')
                            {
                                fout << "cout <<";
                                fin.get(next);
                            }
                            else
                            {
                                fout << "cout >" << next;
                            }
                        }
                        else
                        {
                            fout << "cout " << next;
                            fin.get(next);
                        }
                    }
                    else
                    {
                        fout << "cou" << next;
                        fin.get(next);
                    }
                }
                else
                {
                    fout << "co" << next;
                    fin.get(next);
                }
            }
            else
            {
                fout << "c" << next;
                fin.get(next);
            }
        }
        else
        {
            fout << next;
            fin.get(next);
        }
    }
}


