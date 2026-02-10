#include <iostream>
using namespace std;
int main() 
{
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;
    int** matrix = new int*[rows];
for (int i = 0; i < rows; i++) {
     matrix[i] = new int[cols];
    }
    cout << "Enter matrix elements:\n";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cin >> matrix[i][j];
        }
    }
    cout << "\nMatrix:\n";
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
         cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
for (int i = 0; i < rows; i++) {
    delete[] matrix[i];
}
    delete[] matrix;
    return 0;
}

