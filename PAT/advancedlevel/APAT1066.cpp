#include <stdio.h>

struct Node {
    int value, height;
    Node *left, *right;
    
    Node(int v) {
        value = v;
        height = 0;
    }
};

int getHeight(Node *n) {
    return n == NULL ? -1 : n->height;
}

int max(int a, int b) { return a > b ? a : b; }

Node *rotateWithLeftChild(Node *t) {
    Node *t2 = t->left;
    t->left = t2->right;
    t2->right = t;

    t2->height = max(getHeight(t2->left), getHeight(t2->right)) + 1;
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
    return t2;
}

Node *rotateWithRightChild(Node *t) {
    Node *t2 = t->right;
    t->right = t2->left;
    t2->left = t;

    t2->height = max(getHeight(t2->left), getHeight(t2->right)) + 1;
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
    return t2;
}

Node *doubleRotateWithLeftChild(Node *t) {
    t->left = rotateWithRightChild(t->left);
    return rotateWithLeftChild(t);
}   

Node *doubleRotateWithRightChild(Node *t) {
    t->right = rotateWithLeftChild(t->right);
    return rotateWithRightChild(t);
}

Node *insert(int v, Node *t) {
    if (t == NULL) {
        t = new Node(v);
    } else {
        if (t->value > v) {
            t->left = insert(v, t->left);
            if (getHeight(t->left) - getHeight(t->right) > 1) {
                if (getHeight(t->left->left) > getHeight(t->left->right)) {
                    t = rotateWithLeftChild(t);
                } else {
                    t = doubleRotateWithLeftChild(t);
                }
            }
            
        } else if (t->value < v) {
            t->right = insert(v, t->right);
            if (getHeight(t->right) - getHeight(t->left) > 1) {
                if (getHeight(t->right->right) > getHeight(t->right->left)) {
                    t = rotateWithRightChild(t);
                } else {
                    t = doubleRotateWithRightChild(t);
                }
            }
        } //else {}
    }
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
    
    return t;
}

int main() {
    int n, tmp;
    scanf("%d", &n);
    Node *t = NULL;
    while(n -- ) {
        scanf("%d", &tmp);
        t = insert(tmp, t);
    }
    printf("%d\n",t->value);

    return 0;
}

