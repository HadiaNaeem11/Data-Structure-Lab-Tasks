#include <iostream>
using namespace std;

// -------- Profile Class --------
class Profile {
public:
    int id, age;
    string name, gender, email, interest, dob;
    Profile* next;

    Profile(int i, string n, string g, int a, string e, string in, string d) {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
        next = NULL;
    }
};

// -------- Portal Class --------
class Portal {
    Profile* head;

public:
    Portal() {
        head = NULL;
    }

    // 1. Insert Profile
    void InsertProfile(int id, string name, string gender, int age, string email, string interest, string dob) {
        Profile* newNode = new Profile(id, name, gender, age, email, interest, dob);

        if (head == NULL) {
            head = newNode;
        } else {
            Profile* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Profile Added!\n";
    }

    // 2. Update Profile
    void UpdateProfile(int id) {
        Profile* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Enter new name: ";
                cin >> temp->name;
                cout << "Enter new age: ";
                cin >> temp->age;
                cout << "Enter new email: ";
                cin >> temp->email;

                cout << "Profile Updated!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Profile not found!\n";
    }

    // 3. Delete Profile
    void DeleteProfile(string name) {
        Profile* temp = head;
        Profile* prev = NULL;

        if (temp != NULL && temp->name == name) {
            head = temp->next;
            delete temp;
            cout << "Profile Deleted!\n";
            return;
        }

        while (temp != NULL && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Profile not found!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Profile Deleted!\n";
    }

    // 4. Search Profile
    void searchProfile(string name) {
        Profile* temp = head;

        while (temp != NULL) {
            if (temp->name == name) {
                cout << "Found: " << temp->name << ", Age: " << temp->age << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "Profile not found!\n";
    }

    // 5. Display All
    void Display() {
        Profile* temp = head;

        if (temp == NULL) {
            cout << "No profiles available!\n";
            return;
        }

        while (temp != NULL) {
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Email: " << temp->email << endl;
            cout << "Interest: " << temp->interest << endl;
            cout << "DOB: " << temp->dob << endl;
            cout << "-------------------\n";

            temp = temp->next;
        }
    }
};

// -------- Main Function --------
int main() {
    Portal p;
    int choice;

    do {
        cout << "\n1. Add Profile\n2. Update Profile\n3. Delete Profile\n4. Search Profile\n5. Display All\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, age;
            string name, gender, email, interest, dob;

            cout << "Enter ID: "; cin >> id;
            cout << "Enter Name: "; cin >> name;
            cout << "Enter Gender: "; cin >> gender;
            cout << "Enter Age: "; cin >> age;
            cout << "Enter Email: "; cin >> email;
            cout << "Enter Interest: "; cin >> interest;
            cout << "Enter DOB: "; cin >> dob;

            p.InsertProfile(id, name, gender, age, email, interest, dob);
        }

        else if (choice == 2) {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            p.UpdateProfile(id);
        }

        else if (choice == 3) {
            string name;
            cout << "Enter name to delete: ";
            cin >> name;
            p.DeleteProfile(name);
        }

        else if (choice == 4) {
            string name;
            cout << "Enter name to search: ";
            cin >> name;
            p.searchProfile(name);
        }

        else if (choice == 5) {
            p.Display();
        }

    } while (choice != 6);

    return 0;
}
