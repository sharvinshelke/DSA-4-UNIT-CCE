#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node* head = NULL;

int main() {
    int ch, id;

    do {
        cout << "\n1.Add  2.Display  3.Search  4.Delete  5.Exit\n";
        cin >> ch;

        if (ch == 1) {
            Node* n = new Node;
            cout << "Enter Bag ID: ";
            cin >> n->id;
            n->next = head;
            head = n;
        }
        else if (ch == 2) {
            Node* t = head;
            while (t != NULL) {
                cout << t->id << " -> ";
                t = t->next;
            }
            cout << "NULL\n";
        }
        else if (ch == 3) {
            cout << "Enter ID: ";
            cin >> id;
            Node* t = head;
            while (t != NULL && t->id != id)
                t = t->next;
            cout << (t ? "Found\n" : "Not Found\n");
        }
        else if (ch == 4) {
            cout << "Enter ID: ";
            cin >> id;
            Node *t = head, *p = NULL;
            while (t != NULL && t->id != id) {
                p = t;
                t = t->next;
            }
            if (t != NULL) {
                if (p == NULL) head = t->next;
                else p->next = t->next;
                delete t;
                cout << "Deleted\n";
            } else cout << "Not Found\n";
        }
    } while (ch != 5);

    return 0;
}