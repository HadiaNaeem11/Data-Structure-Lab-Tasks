#include <iostream>
using namespace std;

class Book {
private:
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;

public:
    Book() {}

    Book(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }

    string getId() { return bookId; }
    string getName() { return bookName; }
    double getPrice() { return bookPrice; }
    string getAuthor() { return bookAuthor; }
    string getISBN() { return bookISBN; }

    void setBook(string id, string name, double price, string author, string isbn) {
        bookId = id;
        bookName = name;
        bookPrice = price;
        bookAuthor = author;
        bookISBN = isbn;
    }
};

class Node {
public:
    Book book;
    Node* next;
    Node* prev;

    Node(Book b) {
        book = b;
        next = NULL;
        prev = NULL;
    }
};

class BookList {

    Node* head = NULL;

public:

    void addBook(string id, string name, double price, string author, string isbn) {

        Book b(id, name, price, author, isbn);
        Node* newNode = new Node(b);

        if (head == NULL) {
            head = newNode;
            head->next = head;
            head->prev = head;
        }
        else {
            Node* last = head->prev;

            last->next = newNode;
            newNode->prev = last;

            newNode->next = head;
            head->prev = newNode;
        }
    }

    void removeBook(string id) {

        if (head == NULL) {
            cout << "List empty\n";
            return;
        }

        Node* temp = head;

        do {

            if (temp->book.getId() == id) {

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                if (temp == head)
                    head = temp->next;

                delete temp;

                cout << "Book deleted\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Book ID not found\n";
    }

    void updateBook(string id, string name, double price, string author, string isbn) {

        Node* temp = head;

        if (head == NULL)
            return;

        do {

            if (temp->book.getId() == id) {

                temp->book.setBook(id, name, price, author, isbn);

                cout << "Book updated\n";
                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Book not found\n";
    }

    void printBooks() {

        if (head == NULL) {
            cout << "Empty\n";
            return;
        }

        Node* temp = head;

        do {

            cout << temp->book.getId() << " "
                << temp->book.getName() << " "
                << temp->book.getPrice() << " "
                << temp->book.getAuthor() << " "
                << temp->book.getISBN() << endl;

            temp = temp->next;

        } while (temp != head);
    }

    void printBook(string id) {

        Node* temp = head;

        if (head == NULL)
            return;

        do {

            if (temp->book.getId() == id) {

                cout << temp->book.getName() << " "
                    << temp->book.getPrice() << " "
                    << temp->book.getAuthor() << endl;

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Book not found\n";
    }
};

int main() {

    BookList list;

    cout << "---Add 5 books data\n";
    list.addBook("BK1", "Computer Science", 40, "John","001");
    list.addBook("BK2", "Data Structures", 50, "Sara", "002");
    list.addBook("BK3", "Cyber Security", 60, "David", "003");
    list.addBook("BK4", "Computer Arts", 70, "Tom", "004");
    list.addBook("BK5", "Software Engineering", 90, "Mia", "005");

    cout << "\n";
    cout << "---All Books Data---\n";
    list.printBooks();
    cout << "\n";

    cout << "---Remove books data by ID (removed ID:BK2 AND X1)\n";
    list.removeBook("BK2");
    list.removeBook("X1");
    cout << "For X1 it shows error message!\n";

    cout << "\n";
    cout << "---After removing Book ID:BK2 linked list is:\n";
    list.printBooks();
    cout << "\n";

    cout << "---Update Book BK3 data:\n";
    list.updateBook("BK3", "Advanced security",80, "David","003");
    list.printBook("BK3");

}
