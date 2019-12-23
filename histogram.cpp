#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct node {
  int data;
  int count;
};


vector<node> insertOrdered(vector<node> hist, int num);

int main() {
  cout << "Enter number of grades:" << endl;
  int len;
  cin >> len;
  int* array = new int[len];
  cout << "Enter grades (each on a new line):" << endl;
  for (int i = 0; i < len; i++) {
    int temp;
    cin >> temp;
    array[i] = temp;
  }

  vector<node> hist;
  for (int i = 0; i < len; i++) {
    int temp = array[i];
    bool in = false;
    for (int j = 0; j < hist.size(); j++) {
      if(array[i] == hist[j].data) {
	hist[j].count++;
	in = true;
      }
    }

    if(!in) {
      hist = insertOrdered(hist, temp);
    }
  }

  cout << "Histogram:" << endl;
  
  for(int i = 0; i < hist.size(); i++) {
    cout << right << setw(3) << hist[i].data << " ";
    for (int j = 0; j < hist[i].count; j++)
      cout << "*";
    cout << endl;
    //cout << "num: " << hist[i].data << " count: " << hist[i].count << endl;

  }
  
}

vector<node> insertOrdered(vector<node> hist, int num) {
  node node;
  node.data = num;
  node.count = 1;
  if(hist.size() == 0){
    hist.push_back(node);
    return hist;
  }
  int pos = 0;
  for (int i = 0; i < hist.size(); i++){
    if (num > hist[i].data)
      pos++;
  }
  hist.insert(hist.begin() + pos, node);
  return hist;
}
