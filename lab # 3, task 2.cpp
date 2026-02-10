#include <iostream>
using namespace std;

int main() {
    char* ch = new char;   // dynamic allocation

    cout << "Enter a character: ";
    cin >> *ch;

    cout << "Stored character: " << *ch << endl;

    delete ch;   // deallocate memory

    return 0;
}

