#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()

{
    //variable declarations
    string matrix_values;
    int value;
    int x = 0, y = 0, m = 0, n = 0;
    int i = 0, j = 0;
   
    //matrix declaration
    int mat1[10][10], mat2[10][10], res[10][10];
    
    //Prompt the user to enter the first matrix
    cout << "Enter first matrix:\n";
    while (true)
    {
        getline(cin, matrix_values);
        if (matrix_values.empty())
        {
            break;
        }
        stringstream ss(matrix_values);
        j = 0;
        while (ss >> value)
        {
            mat1[i][j] = value;
            j++;
            if (ss.peek() == ' ')
                ss.ignore();
        }
        i++;
    }
    x = i;
    y = j;
    cout << "Enter second matrix:\n";
    i = 0;
    while (true){
        getline(cin, matrix_values);
        if (matrix_values.empty()){
            break;
        }
        stringstream ss(matrix_values);
        j = 0;
        while (ss >> value){
            mat2[i][j] = value;
            j++;
            if (ss.peek() == ' ')
                ss.ignore();
        }
        i++;
    }
    m = i;
    n = j;
    if (y == m){
        for (i = 0; i < x; i++){
            for (j = 0; j < n; j++){
                res[i][j] = 0;
                for (int k = 0; k < m; k++){
                    res[i][j] = res[i][j] + (mat1[i][k] * mat2[k][j]);
                }
            }
        }
        cout << "The product is:\n";
        for (i = 0; i < x; i++){
            for (j = 0; j < n; j++){
                cout << res[i][j];
                if (j != n-1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "The two matrices have incompatible dimensions." << endl;
    }
    system("pause");
    return 0;
}
