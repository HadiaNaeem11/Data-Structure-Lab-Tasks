#include <iostream>
using namespace std;

// -------- Node --------
struct Node {
    string name;
    Node* next;
};

// -------- Class --------
class EmployeeList {
    Node* head;

public:
    EmployeeList() {
        head = NULL;
    }

    // ADD Employee (at end)
    void add(string name) {
        Node* newNode = new Node();
        newNode->name = name;

        // Empty list
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            cout << "Added successfully\n";
            return;
        }

        // Check duplicate
        Node* temp = head;
        do {
            if (temp->name == name) {
                cout << "Name already exists!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        // Insert at end
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;

        cout << "Added successfully\n";
    }

    // DELETE Employee
    void del(string name) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        // Case: only one node
        if (head->next == head && head->name == name) {
            delete head;
            head = NULL;
            cout << "Deleted successfully\n";
            return;
        }

        // Case: delete head
        if (head->name == name) {
            Node* last = head;
            while (last->next != head)
                last = last->next;

            head = head->next;
            last->next = head;

            delete curr;
            cout << "Deleted successfully\n";
            return;
        }

        // Case: middle or last
        prev = head;
        curr = head->next;

        while (curr != head && curr->name != name) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == head) {
            cout << "Name not found\n";
            return;
        }

        prev->next = curr->next;
        delete curr;

        cout << "Deleted successfully\n";
    }

    // SEARCH Employee
    void search(string name) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->name == name) {
                cout << "Found successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Name not found\n";
    }

    // UPDATE Employee
    void update(string oldName, string newName) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->name == oldName) {
                temp->name = newName;
                cout << "Updated successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Name not found\n";
    }

    // DISPLAY
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        cout << "Employees: ";
        do {
            cout << temp->name << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

// -------- Main --------
int main() {
    EmployeeList list;
    int choice;
    string name, newName;

    do {
        cout << "\n1. Add Employee\n2. Delete Employee\n3. Search Employee\n";
        cout << "4. Update Employee\n5. Display\n6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            list.add(name);
        }
        else if (choice == 2) {
            cout << "Enter name to delete: ";
            cin >> name;
            list.del(name);
        }
        else if (choice == 3) {
            cout << "Enter name to search: ";
            cin >> name;
            list.search(name);
        }
        else if (choice == 4) {
            cout << "Enter old name: ";
            cin >> name;
            cout << "Enter new name: ";
            cin >> newName;
            list.update(name, newName);
        }
        else if (choice == 5) {
            list.display();
        }

    } while (choice != 6);

    return 0;
}
