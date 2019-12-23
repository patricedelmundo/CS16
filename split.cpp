#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string target, string delimiter);

int main() {
  string target, delimiter;
  vector<string> substrings;
  cout << "Enter string to split:" << endl;
  getline(cin, target);
  cout << "Enter delimiter string:" << endl;
  getline(cin, delimiter);

  substrings = split(target, delimiter);

  cout << "The substrings are: ";
  int size = substrings.size();

  if (size == 1)
    cout << "\"" << substrings[0] << "\"";
  else {
    for (int i = 0; i < size-1; i++) {
      cout << "\"" << substrings[i] << "\", ";
    }
    cout << "\"" << substrings[size-1] << "\"";
  }
  cout << endl;

  return 0;
}

vector<string> split(string target, string delimiter) {
  vector<string> result;
  int bPos = 0;
  int ePos = target.find(delimiter);
  bool flag = false;
  
  while (ePos != string::npos) {
    string temp = target.substr(bPos, ePos-bPos);
    if(temp != "")
       result.push_back(temp);
    flag = true;
    bPos = ePos+1;
    ePos = target.find(delimiter, bPos);
  }
  string temp = target.substr(bPos, ePos-bPos);
  if (flag && temp != "")
    result.push_back(temp);
  if (!flag && temp != "" && ePos == string::npos)
    result.push_back(target);
  
  return result;
}
