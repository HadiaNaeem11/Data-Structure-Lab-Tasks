#include <iostream>
using namespace std;

// -------- Node Structure --------
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// -------- Class --------
class DoublyList {
    Node* head;

public:
    DoublyList() {
        head = NULL;
    }

    // Create List from User
    void createList(int n) {
        int value;
        Node* newNode;

        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;

            newNode = new Node();
            newNode->data = value;
            newNode->prev = NULL;
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
                newNode->prev = temp;
            }
        }
    }

    // b) Insert at Beginning
    void addAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;

        cout << "Inserted at beginning\n";
    }

    // c) Insert after specific value (e.g., 45)
    void addAfterValue(int target, int value) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;

                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != NULL)
                    temp->next->prev = newNode;

                temp->next = newNode;

                cout << "Inserted after " << target << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Value not found!\n";
    }

    // d) Delete at Beginning
    void deleteAtBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != NULL)
            head->prev = NULL;

        delete temp;

        cout << "Deleted from beginning\n";
    }

    // e) Delete after specific value (e.g., 45)
    void deleteAfterValue(int target) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == target && temp->next != NULL) {
                Node* delNode = temp->next;

                temp->next = delNode->next;

                if (delNode->next != NULL)
                    delNode->next->prev = temp;

                delete delNode;

                cout << "Deleted node after " << target << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Value not found or no node after it!\n";
    }

    // Display
    void display() {
        Node* temp = head;

        cout << "List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// -------- Main --------
int main() {
    DoublyList list;
    int n, choice, value, target;

    cout << "Enter number of nodes: ";
    cin >> n;

    list.createList(n);

    do {
        cout << "\n1. Insert at Beginning\n";
        cout << "2. Insert after value\n";
        cout << "3. Delete at Beginning\n";
        cout << "4. Delete after value\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.addAtBeginning(value);
        }
        else if (choice == 2) {
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter new value: ";
            cin >> value;
            list.addAfterValue(target, value);
        }
        else if (choice == 3) {
            list.deleteAtBeginning();
        }
        else if (choice == 4) {
            cout << "Enter target value: ";
            cin >> target;
            list.deleteAfterValue(target);
        }
        else if (choice == 5) {
            list.display();
        }

    } while (choice != 6);

    return 0;
}
