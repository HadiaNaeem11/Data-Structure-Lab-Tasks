#include <iostream>
using namespace std;
class Mobile {
private:
    string brand;
    int unitsOnHand;
    double price;
public:
 // Constructor
 Mobile(string b = "", int u = 0, double p = 0.0) {
     brand = b;
     unitsOnHand = u;
     price = p;
}
// Setters
    void setBrand(string b) { brand = b; }
    void setUnits(int u) { unitsOnHand = u; }
    void setPrice(double p) { price = p; }
// Getters
    string getBrand() { return brand; }
    int getUnits() { return unitsOnHand; }
    double getPrice() { return price; }
};
// Node Structure
struct Node {
    Mobile data;
    Node* next;
};
//Store Class (Linked List) 
class Store {
private:
    Node* head;
public:
    Store() {
    head = NULL;
}
// Inserting at Start
  void insertAtStart(Mobile m) {
      Node* newNode = new Node;
      newNode->data = m;
      newNode->next = head;
      head = newNode;
}
 // Inserting at End
    void insertAtEnd(Mobile m) {
        Node* newNode = new Node;
        newNode->data = m;
        newNode->next = NULL;

      if (head == NULL) {
        head = newNode;
          return;
}
     Node* temp = head;
        while (temp->next != NULL) {
           temp = temp->next;
 }
        temp->next = newNode;
    }
// Inserting in Between (after specific brand)
void insertInBetween(string afterBrand, Mobile m) {
     Node* temp = head;
        while (temp != NULL && temp->data.getBrand() != afterBrand) {
           temp = temp->next;
}
 if (temp == NULL) {
       cout << "Mobile not found!\n";
         return;
  }
       Node* newNode = new Node;
       newNode->data = m;
       newNode->next = temp->next;
       temp->next = newNode;
    }
// Deleting from Start
   void deleteFromStart() {
      if (head == NULL) {
         cout << "List is empty!\n";
            return;
       }
        Node* temp = head;
        head = head->next;
        delete temp;
         }
// Deleting from End
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
// Deletion in Between (by brand)
    void deleteInBetween(string brand) {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
          if (head->data.getBrand() == brand) {
              deleteFromStart();
               return;
        }
        Node* temp = head;
        while (temp->next != NULL && temp->next->data.getBrand() != brand) {
            temp = temp->next;
        }
            if (temp->next == NULL) {
                cout << "Mobile not found!\n";
                  return;
        }
        Node* del = temp->next;
        temp->next = del->next;
        delete del;
    }
 // Displaying the List
    void display() {
        if (head == NULL) {
            cout << "No mobiles in store!\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << "Brand: " << temp->data.getBrand() << endl;
            cout << "Units: " << temp->data.getUnits() << endl;
            cout << "Price: " << temp->data.getPrice() << endl;
            cout << "----------------------\n";
            temp = temp->next;
        }
    }
};
//  Main Function
int main() {
    Store s;
  // Creating Mobiles
    Mobile m1("Samsung", 10, 350000);
    Mobile m2("Apple", 5, 150000);
    Mobile m3("Oppo", 8, 70000);
    Mobile m4("Vivo", 6, 55000);
  // Insert Operations
    s.insertAtStart(m1);
    s.insertAtEnd(m2);
    s.insertAtEnd(m3);
    s.insertInBetween("Samsung", m4);
    cout << "\n--- Mobiles After Insertion ---\n";
    s.display();
  // Delete Operations
    s.deleteFromStart();
    s.deleteFromEnd();
    s.deleteInBetween("Oppo");
    cout << "\n--- Mobiles After Deletion ---\n";
    s.display();
    return 0;
}
