#include <iostream>
using namespace std;
struct Product {
    char name[10];
    int code;
    float price;
};
int main() {
    int n;
    cout << "Enter number of products: ";
    cin >> n;
    Product* products = new Product[n];   
for (int i = 0; i < n; i++) {
    cout << "\nEnter product " << i + 1 << " details\n";
    cout << "Name: ";
    cin >> products[i].name;
    cout << "Code: ";
    cin >> products[i].code;
    cout << "Price: ";
    cin >> products[i].price;
    }
    cout << "\n--- Product List ---\n";
  for (int i = 0; i < n; i++) {
     cout << products[i].name << "  "
          << products[i].code << "  "
          << products[i].price << endl;
    }
    delete[] products;  
    return 0;
}

