#include <iostream>

using namespace std;

void makeHist(string str, int (&hist)[26]);

int main() {
  string str1, str2;
  cout << "Enter first string:" << endl;
  getline(cin, str1);
  cout << "Enter second string:" << endl;
  getline(cin, str2);

  int hist1[26];
  int hist2[26];
  makeHist(str1, hist1);
  makeHist(str2, hist2);
  
  
  bool comp = true;
  for (int i = 0; i < 26; i++) {
    if(hist1[i] != hist2[i])
      comp = false;
  }
  if (comp)
    cout << "The strings are anagrams." << endl;
  else
    cout << "The strings are not anagrams." << endl;
  
}

void makeHist(string str, int (&hist)[26]) {
  for (int i = 0; i < 26; i++)
    hist[i] = 0;
  int len = str.length();
  for (int i = 0; i < len; i++) {
    int pos = tolower(str[i]) - 'a';
    if (pos<26)
      hist[pos]++;
    
  }
}
