#include <iostream>
using namespace std;

// -------- Node Structure --------
struct Node {
    float rain;
    Node* prev;
    Node* next;
};

// -------- Class --------
class RainfallList {
    Node* head;

public:
    RainfallList() {
        head = NULL;
    }

    // Insert at end (for 7 days)
    void insert(float value) {
        Node* newNode = new Node();
        newNode->rain = value;
        newNode->next = NULL;
        newNode->prev = NULL;

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

    // Display Results
    void calculate() {
        if (head == NULL) {
            cout << "No data!\n";
            return;
        }

        Node* temp = head;
        float total = 0;
        int count = 0;

        float highest = head->rain;
        float lowest = head->rain;
        int highDay = 1, lowDay = 1;
        int day = 1;

        // Traverse list
        while (temp != NULL) {
            total += temp->rain;

            if (temp->rain > highest) {
                highest = temp->rain;
                highDay = day;
            }

            if (temp->rain < lowest) {
                lowest = temp->rain;
                lowDay = day;
            }

            temp = temp->next;
            day++;
            count++;
        }

        float avg = total / count;

        cout << "\nTotal Rainfall: " << total << endl;
        cout << "Average Rainfall: " << avg << endl;
        cout << "Highest Rainfall: Day " << highDay << " (" << highest << ")\n";
        cout << "Lowest Rainfall: Day " << lowDay << " (" << lowest << ")\n";

        // Rainfall after 5th node
        temp = head;
        int pos = 1;

        while (temp != NULL && pos < 6) {
            temp = temp->next;
            pos++;
        }

        if (temp != NULL)
            cout << "Rainfall after 5th day: " << temp->rain << endl;
        else
            cout << "No data after 5th day\n";
    }
};

// -------- Main --------
int main() {
    RainfallList list;
    float value;

    cout << "Enter rainfall for 7 days:\n";

    for (int i = 1; i <= 7; i++) {
        cout << "Day " << i << ": ";
        cin >> value;

        // Input validation
        if (value < 0) {
            cout << "Invalid! Enter non-negative value.\n";
            i--; // repeat input
            continue;
        }

        list.insert(value);
    }

    list.calculate();

    return 0;
}
