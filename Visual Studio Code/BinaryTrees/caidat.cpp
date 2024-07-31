#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* right;   // pointer to the right child
    Node* left;    // pointer to the left child

    // constructor
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
Node *makeNode(int x){

    return new Node(x);
}
int main() {
    Node* root = new Node(1);  // creating a new node with data 10
    Node* node1 = makeNode(2);
    Node* node2 = makeNode(3);
    Node* node3 = makeNode(4); 
    Node* node4 = makeNode(5); 
    root->left = node1;
    root->right = node2;
    node1->right = node4;
    node1->left = node3;
    cout<<root<<endl;
    cout<<node1<<endl;
    cout<<node2<<endl;
    cout<<root->data<<endl;
    cout<<root->left<<" "<<root->right<<endl;
    cout<<node1->left<<" "<<node1->right<<endl;
    delete root;
    

    return 0;
}
