#include <iostream>

using namespace std;

long long C(int n, int r)
{
    long long f[n + 1];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = i * f[i - 1];
    return f[n] / f[r] / f[n - r];
}

int main()
{
    int n, r;
    {
        cout<<"Enter r (number of things to choose):\n";                     //input for number of things to choose
        cin>>r;

        cout<<"Enter n (the number of things to choose from):\n";            //input for number of things to choose from
        cin>>n;
        
        long ans = C(n, min(r, n-r));
        
       
        /* Nested if/else statements for output grammar. Adjustments are
           made for plural and sigular forms of ans, n, and, r. Basically,
           for ans = 1, r = 1, n = 1, the output displayed will be:
         
          "There is 1 way to choose, 1 thing from a set of 1 thing."
                                      versus
        "There are 1 ways to choose 1 things from a set of 1 things." */

        
        if (ans > 1 || 0){                                                  //condition for ans not equal to 1
            
            cout<<"There are "<<ans<<" ways to choose ";
            
            if (r > 1 || r == 0){                                           //condition for r not equal to 1
                cout<<r<<" things from a set of ";
                if (n > 1 || n == 0){                                       //condition for n not equal to 1

                    cout<<n<<" things."<<endl;
                }
                else {                                                      //condition for n equal to 1
                    cout<<n<<" thing."<<endl;
                }
            }
            else {                                                          //condition for r equal to 1
                
                cout<<r<<" thing from a set of ";
                
                if (n > 1 || n == 0){                                       //condition for n not equal to 1
                    cout<<n<<" things."<<endl;
                }
                else {                                                      //condition for n equal to 1
                    cout<<n<<" thing."<<endl;
                }
                
            }
    }
        else{                                                               //conditon for ans == 1
            cout<<"There is "<<ans<<" way to choose ";
           
            if ( r > 1 || r == 0){                                          // condition for r not equal to 1
                cout<<r<<" things from a set of ";
                
                if (n > 1 || n == 0){                                       //condition for n not equal to 1
                    cout<<n<<" things."<<endl;
                }
                else {                                                      //condition for n equal to 1
                    cout<<n<<" thing."<<endl;
                }
            }
            
            else {
                cout<<r<<" thing from a set of ";

                if (n > 1 || n == 0){                                       //condition for n not equal to 1
                    cout<<n<<" things."<<endl;
                }
                else {                                                      //condition for n equal to 1
                    cout<<n<<" thing."<<endl;
                }
        }
}
}
}

