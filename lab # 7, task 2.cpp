#include <iostream>
using namespace std;

// ----------- Inventory Class -----------
class Inventory {
private:
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    Inventory() {}

    Inventory(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    void getData() {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Year: " << manufactYear << endl;
        cout << "Lot Number: " << lotNum << endl;
    }
};

// ----------- Node Class -----------
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory i) {
        data = i;
        next = NULL;
    }
};

// ----------- Stack Class -----------
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(Inventory i) {
        Node* newNode = new Node(i);
        newNode->next = top;
        top = newNode;
        cout << "Part added to inventory.\n";
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Inventory is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemoved Part Details:\n";
        temp->data.getData();

        top = top->next;
        delete temp;
    }

    // Display remaining stack
    void display() {
        if (top == NULL) {
            cout << "No parts remaining in inventory.\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Inventory:\n";

        while (temp != NULL) {
            temp->data.getData();
            cout << "------------------\n";
            temp = temp->next;
        }
    }
};

// ----------- Main Program -----------
int main() {

    Stack s;
    int choice;

    do {
        cout << "\n1. Add Part\n2. Remove Part\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int sNum, year, lot;

            cout << "Enter Serial Number: ";
            cin >> sNum;

            cout << "Enter Manufacture Year: ";
            cin >> year;

            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory obj(sNum, year, lot);
            s.push(obj);
        }
        else if (choice == 2) {
            s.pop();
        }

    } while (choice != 3);

    // Display remaining items
    cout << "\n--- Final Inventory ---\n";
    s.display();

    return 0;
}
