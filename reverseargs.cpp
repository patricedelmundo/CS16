#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)

{
    for (int ctr=argc; ctr; ctr--)
        cout << argv[ctr-1] << " "; // i just had to add -1 to ctr
    return 0;
}
