#include <iostream>
using namespace std;
int main() {
    int arr[100], n, temp;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter array elements:\n";
  for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
   for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
    cout << "Reversed array:\n";
  for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
