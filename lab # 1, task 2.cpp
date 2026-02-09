#include <iostream>
using namespace std;
int main() {
    int arr[100], n, index, newValue;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements:\n";
  for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter index to update: ";
    cin >> index;
    cout << "Enter new value: ";
    cin >> newValue;
    if (index >= 0 && index < n) {
        arr[index] = newValue;
        cout << "Updated array:\n";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    } else {
        cout << "Invalid index!";
    }
    return 0;
}
