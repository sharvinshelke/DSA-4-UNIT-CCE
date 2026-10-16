#include <iostream>
using namespace std;

struct Node {
    int id;
    Node *l, *r;
    Node(int x) { id=x; l=r=NULL; }
};

Node* insert(Node* t, int x) {
    if (!t) return new Node(x);
    if (x < t->id) t->l=insert(t->l,x);
    else if (x > t->id) t->r=insert(t->r,x);
    return t;
}

Node* del(Node* t, int x) {
    if (!t) return NULL;
    if (x < t->id) t->l=del(t->l,x);
    else if (x > t->id) t->r=del(t->r,x);
    else {
        if (!t->l || !t->r) {
            Node* p=t->l ? t->l : t->r;
            delete t; return p;
        }
        Node* p=t->r;
        while (p->l) p=p->l;
        t->id=p->id;
        t->r=del(t->r,p->id);
    }
    return t;
}

int h(Node* t) {
    if (!t) return 0;
    return 1+max(h(t->l),h(t->r));
}

int leaf(Node* t) {
    if (!t) return 0;
    if (!t->l && !t->r) return 1;
    return leaf(t->l)+leaf(t->r);
}

int internal(Node* t) {
    if (!t || (!t->l && !t->r)) return 0;
    return 1+internal(t->l)+internal(t->r);
}

int one(Node* t) {
    if (!t) return 0;
    return ((t->l==NULL) != (t->r==NULL))
           +one(t->l)+one(t->r);
}

void display(Node* t) {
    if (t) {
        display(t->l);
        cout << t->id << " ";
        display(t->r);
    }
}

int main() {
    Node* root=NULL;
    int ch,x;

    do {
        cout << "\n1.Insert 2.Delete 3.Display";
        cout << "\n4.Properties 5.Exit\nChoice: ";
        cin >> ch;

        if (ch==1) {
            cout << "Employee ID: "; cin >> x;
            root=insert(root,x);
        }
        else if (ch==2) {
            cout << "Delete ID: "; cin >> x;
            root=del(root,x);
        }
        else if (ch==3) display(root);
        else if (ch==4) {
            cout << "Height: " << h(root);
            cout << "\nLeaf nodes: " << leaf(root);
            cout << "\nInternal nodes: " << internal(root);
            cout << "\nNodes with one child: " << one(root);
        }
    } while (ch!=5);
    return 0;
}
