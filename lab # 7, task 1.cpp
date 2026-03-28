#include <iostream>
using namespace std;

// ---------------- Book Structure ----------------
class Book {
public:
    string title;
    double price;
    int edition;
    int pages;

    Book() {}

    Book(string t, double p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
    }
};

// ---------------- Node ----------------
class Node {
public:
    Book data;
    Node* next;

    Node(Book b) {
        data = b;
        next = NULL;
    }
};

// ---------------- Stack ----------------
class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(Book b) {
        Node* newNode = new Node(b);
        newNode->next = top;
        top = newNode;
        cout << "Book pushed: " << b.title << endl;
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;
        cout << "Book popped: " << temp->data.title << endl;

        top = top->next;
        delete temp;
    }

    // Peek (top element)
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }

        cout << "Top Book:\n";
        cout << "Title: " << top->data.title << endl;
        cout << "Price: " << top->data.price << endl;
        cout << "Edition: " << top->data.edition << endl;
        cout << "Pages: " << top->data.pages << endl;
    }

    // Display all books
    void display() {
        if (top == NULL) {
            cout << "Stack is empty!\n";
            return;
        }

        Node* temp = top;

        cout << "\nRemaining Books in Stack:\n";
        while (temp != NULL) {
            cout << temp->data.title << " | "
                 << temp->data.price << " | "
                 << temp->data.edition << " | "
                 << temp->data.pages << endl;

            temp = temp->next;
        }
    }
};

// ---------------- Main ----------------
int main() {

    Stack s;

    // 1. Push 5 books
    cout << "--- Pushing Books ---\n";
    s.push(Book("C++ Basics", 20, 1, 150));
    s.push(Book("Data Structures", 30, 2, 200));
    s.push(Book("Java", 40, 3, 220));
    s.push(Book("Operating Systems", 50, 4, 400));
    s.push(Book("Python", 60, 5, 350));

    // 2. Peek top element
    cout << "\n--- Peek Top ---\n";
    s.peek();

    // 3. Pop 2 books
    cout << "\n--- Popping 2 Books ---\n";
    s.pop();
    s.pop();

    // 4. Display remaining books
    cout << "\n--- Display Stack ---\n";
    s.display();

    return 0;
}
