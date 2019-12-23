#include <iostream>
#include <iomanip>

using namespace std;

bool isPalindrome(string s)
{

  if(s.length() == 0 || s.length() == 1)
    return true;
  if(isdigit(s.at(0)))
    {
      if(s.at(0) == s.at(s.length()-1))
	return isPalindrome(s.substr(1, s.length()-2));
    }
  else
    {
      if(tolower(s.at(0)) == tolower(s.at(s.length()-1)))
	return isPalindrome(s.substr(1, s.length()-2));
    }

  return false;
}
int main()
{
  //User's string input
  cout<<"Enter string:\n";
  string s;
  cin>>s;

  if(isPalindrome(s))
    cout<<"\""<<s<<"\""<<" is a palindrome.";
  else
    cout<<"\""<<s<<"\""<<" is not a palindrome.";
  cout<<endl;
  return 0;
}
