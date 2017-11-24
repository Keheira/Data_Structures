#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Tree() {
    root = NULL;
}

bool Tree::Empty() { // return true if the tree is empty, otherwise return false
    if (root == NULL)
        return true;
    return false;
}

int Tree::Height(TreeNode* t){ //keep track of tree height
    
}
void Tree::Insert(DataType x) { //insert a value x
    if(!IsThere(x))
        Add(x, root);
}

void Tree::Add(DataType target, TreeNode *t) { //recursive insert
    if(t == NULL) {
	t = new TreeNode;
	t->data = target;
	t->leftchild = NULL;
	t->rightchild = NULL;
        root = t;
    }
    else if(target > t->data) Add(target, t->rightchild);
    else if(target < t->data) Add(target, t->leftchild);
}

TreeNode* Tree::singleLeft(TreeNode *t){ //single rotation on a left node
    TreeNode *n = t;
    t->leftchild = n->rightchild;
    n->rightchild = t;
}

TreeNode* Tree::singleRight(TreeNode *t){ //single rotation on a right node
    TreeNode *n = t;
    t->rightchild = n->leftchild;
    n->leftchild = t;
}

TreeNode* Tree::doubleLeft(TreeNode *t){ //double rotation on a left node
    t->leftchild = singleRight(t->leftchild);
    return singleLeft(t);
}

TreeNode* Tree::doubleRight(TreeNode *t){ //double rotation on a right node
    t->rightchild = singleLeft(t->leftchild);
    return singleRight(t);
}

bool Tree::IsThere(DataType x) { //return true if x is in the tree, otherwise return false
    TreeNode *p = root;
    if (Empty()) //check to see if there are any TreeNodes if not return false
        return false;
    while (p != NULL) {
        if (x == p->data)//check TreeNode value
            return true;
        if (x < p->data)//if less then move left and check
            p = p->leftchild;
        if (x > p->data)//if more than move right
            p = p->rightchild;
    }
}

void Tree::Delete(DataType x) { //if value x is in the tree, remove x
    TreeNode *p = root;
    TreeNode *dummy = NULL;
    for (TreeNode *p = root; p != NULL;) {
        dummy = p;
        if (x == p->data) {
            if(p->leftchild != NULL && p->rightchild != NULL){//case if TreeNode has no children
                delete p;
            }
            if((p->leftchild == NULL && p->rightchild != NULL) || (p->leftchild != NULL && p->rightchild == NULL)){//case if TreeNode has 1 child
                if(p->leftchild == NULL){//TreeNode only has a left child
                    dummy->rightchild = NULL;
                    delete p;
                }
                if(p->rightchild == NULL){//TreeNode only has a left child
                    dummy->leftchild = NULL;
                    delete p;
                }
            }
            if(p->leftchild != NULL && p->rightchild != NULL){//case if TreeNode has 2 children
                TreeNode *temp = p->leftchild;
                p->rightchild = temp->rightchild->rightchild;
                root = temp;
                delete p;
            }
        }
        if (x < p->data)//if less then move left and check
            dummy = dummy->leftchild;
        else if (x > dummy->data)//if more than move right
            dummy = dummy->rightchild;
    }
}

void Tree::Display() { //Display the data stored from smallest to largest based on dish number
    Preorder(root); //display tree on first look
    Inorder(root); //display tree on second look
    Postorder(root); //display tree on third look
}

void Tree::Preorder(TreeNode* t) { //display tree on first look
    cout<<"The preorder: "<<endl;
    if(t != NULL){
        cout << t->data;
        if(t->leftchild != NULL)
                Preorder(t->leftchild);
        if(t->rightchild != NULL)
                Preorder(t->rightchild);
    }
    else
        cout<<"Invalid"<<endl;
}

void Tree::Inorder(TreeNode* t) { //display tree on second look
    cout<<"The inorder: "<<endl;
    if(t != NULL){
        if(t->leftchild != NULL)
                Inorder(t->leftchild);
        cout << t->data;
        if(t->rightchild != NULL)
                Inorder(t->rightchild);
    }
    else
        cout<<"Invalid"<<endl;
}

void Tree::Postorder(TreeNode* t){ //display tree on third look
    cout<<"The postorder: "<<endl;
    if(t != NULL){
        if(t->leftchild != NULL)
                Postorder(t->leftchild);
        if(t->rightchild != NULL)
                Postorder(t->rightchild);
        cout << t->data;
    }
    else
        cout<<"Invalid"<<endl;
}
