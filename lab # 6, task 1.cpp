#include <iostream>
using namespace std;

// -------- Node --------
struct Node {
    int data;
    Node* next;
};

// -------- Class --------
class CircularList {
    Node* head;

public:
    CircularList() {
        head = NULL;
    }

    // Insert BEFORE (at beginning)
    void insertBefore(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        // Case 1: Empty list
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        // Find last node
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        // Insert at beginning
        newNode->next = head;
        temp->next = newNode;
        head = newNode;

        cout << "Inserted at beginning\n";
    }

    // Insert AFTER (at end)
    void insertAfter(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        // Case 1: Empty list
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        // Find last node
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        // Insert at end
        temp->next = newNode;
        newNode->next = head;

        cout << "Inserted at end\n";
    }

    // Delete node (all cases)
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        // Case 1: Only one node
        if (head->next == head && head->data == value) {
            delete head;
            head = NULL;
            cout << "Deleted\n";
            return;
        }

        // Case 2: Delete head
        if (head->data == value) {
            Node* last = head;

            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;

            delete curr;
            cout << "Deleted head\n";
            return;
        }

        // Case 3: Delete middle or last
        prev = head;
        curr = head->next;

        while (curr != head && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            cout << "Value not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;

        cout << "Deleted\n";
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Circular List: ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

// -------- Main --------
int main() {
    CircularList list;
    int choice, value;

    do {
        cout << "\n1. Insert Before (Beginning)\n";
        cout << "2. Insert After (End)\n";
        cout << "3. Delete\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            list.insertBefore(value);
        }
        else if (choice == 2) {
            cout << "Enter value: ";
            cin >> value;
            list.insertAfter(value);
        }
        else if (choice == 3) {
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
        }
        else if (choice == 4) {
            list.display();
        }

    } while (choice != 5);

    return 0;
}
