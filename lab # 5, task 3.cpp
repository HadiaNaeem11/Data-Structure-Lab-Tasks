#include <iostream>
using namespace std;

// -------- Node --------
struct Player {
    string name;
    int score;
    Player* next;
    Player* prev;
};

// -------- Class --------
class GolfList {
    Player* head;

public:
    GolfList() {
        head = NULL;
    }

    // Add Player (Sorted by score)
    void addPlayer(string name, int score) {
        Player* newNode = new Player();
        newNode->name = name;
        newNode->score = score;
        newNode->next = NULL;
        newNode->prev = NULL;

        // Case 1: Empty list
        if (head == NULL) {
            head = newNode;
            return;
        }

        // Case 2: Insert at beginning
        if (score < head->score) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        // Case 3: Insert in middle or end
        Player* temp = head;
        while (temp->next != NULL && temp->next->score < score) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = newNode;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete Player by name
    void deletePlayer(string name) {
        Player* temp = head;

        while (temp != NULL) {
            if (temp->name == name) {

                // If deleting head
                if (temp == head) {
                    head = temp->next;
                    if (head != NULL)
                        head->prev = NULL;
                } else {
                    temp->prev->next = temp->next;
                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;
                }

                delete temp;
                cout << "Player deleted!\n";
                return;
            }
            temp = temp->next;
        }

        cout << "Player not found!\n";
    }

    // Display all players
    void display() {
        Player* temp = head;

        if (temp == NULL) {
            cout << "List is empty\n";
            return;
        }

        cout << "\nPlayers List:\n";
        while (temp != NULL) {
            cout << temp->name << " - " << temp->score << endl;
            temp = temp->next;
        }
    }

    // Lowest score player
    void lowestScore() {
        if (head == NULL) {
            cout << "No data\n";
            return;
        }

        cout << "Lowest Score: " << head->name << " (" << head->score << ")\n";
    }

    // Players with same score
    void sameScore(int score) {
        Player* temp = head;
        bool found = false;

        while (temp != NULL) {
            if (temp->score == score) {
                cout << temp->name << " ";
                found = true;
            }
            temp = temp->next;
        }

        if (!found)
            cout << "No players with this score";

        cout << endl;
    }

    // Display backward from a player
    void backwardFromPlayer(string name) {
        Player* temp = head;

        // Find player
        while (temp != NULL && temp->name != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Player not found\n";
            return;
        }

        cout << "Backward players:\n";

        temp = temp->prev; // move one step back

        while (temp != NULL) {
            cout << temp->name << " - " << temp->score << endl;
            temp = temp->prev;
        }
    }
};

// -------- Main --------
int main() {
    GolfList g;
    int choice, score;
    string name;

    do {
        cout << "\n1. Add Player\n2. Delete Player\n3. Display All\n";
        cout << "4. Lowest Score\n5. Same Score Players\n6. Backward From Player\n7. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter score: ";
            cin >> score;

            g.addPlayer(name, score);
        }

        else if (choice == 2) {
            cout << "Enter name to delete: ";
            cin >> name;
            g.deletePlayer(name);
        }

        else if (choice == 3) {
            g.display();
        }

        else if (choice == 4) {
            g.lowestScore();
        }

        else if (choice == 5) {
            cout << "Enter score: ";
            cin >> score;
            g.sameScore(score);
        }

        else if (choice == 6) {
            cout << "Enter player name: ";
            cin >> name;
            g.backwardFromPlayer(name);
        }

    } while (choice != 7);

    return 0;
}
