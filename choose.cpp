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
    cout<<"Enter r (number of things to choose):\n";
    cin>>r;

    cout<<"Enter n (the number of things to choose from):\n";
    cin>>n;


    long ans = C(n, min(r, n-r));

    if (ans > 1 || 0){
      cout<<"There are "<<ans<<" ways to choose ";

      if (r > 1 || r == 0){
	cout<<r<<" things from a set of ";

	if (n > 1 || n == 0){
	  cout<<n<<" things."<<endl;
	}

	else {
	  cout<<n<<" thing."<<endl;
	}
      }

      else {
	cout<<r<<" thing from a set of ";
	if (n > 1 || n == 0){
	  cout<<n<<" things."<<endl;
	}

	else {
	  cout<<n<<" thing."<<endl;
	}

      }
    }

    else{
      cout<<"There is "<<ans<<" way to choose ";
      if ( r > 1 || r == 0){
	cout<<r<<" things from a set of ";

	if (n > 1 || n == 0){
	  cout<<n<<" things."<<endl;
	}

	else {
	  cout<<n<<" thing."<<endl;
	}
      }
      else {
	cout<<r<<" thing from a set of ";
	if (n > 1 || n == 0){
	  cout<<n<<" things."<<endl;
	}

	else {
	  cout<<n<<" thing."<<endl;
	}

      }
    }
  }
}
