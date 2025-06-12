#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};

node* buildTree(){
    int d;
    cin>>d;

    if (d==-1){
        return NULL;
    }
    node* root=new node(d);
    root->left=buildTree();
    root->right=buildTree();

    return root;
}

//Trees can be printed in 4 types :- preorder, inorder, postorder and level order

void printIn(node* root){ //Inorder type printing prints left, then root and then right
    if (root==NULL){
        return;
    }
    
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node* root){ //Postorder type printing prints left, then right and then root
    if (root==NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";

}
int main(){
    
    node* root=buildTree();
    printIn(root);
    cout<<endl;
    printPost(root);

    return 0;
}