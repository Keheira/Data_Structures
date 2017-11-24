/* 
 * File:   Tree.h
 * Author: keheira
 *
 * Created on November 5, 2013, 2:16 PM
 */

#ifndef TREE_H
#define	TREE_H

typedef  int DataType;
 
class TreeNode{
friend class Tree;
private:
	TreeNode* leftchild;
	DataType data;
	TreeNode* rightchild;
};
 
class Tree{
public:
    Tree(); //create an empty list by setting first to NULL
    bool Empty(); //return true if the list is empty, otherwise return false
    int Height(TreeNode* t); //keep track of tree height
    void Insert(DataType x); ////insert a value x into a tree
    void Add(DataType target, TreeNode *t); //recursive insert
    TreeNode* singleLeft(TreeNode *t); //single rotation on a left node
    TreeNode* singleRight(TreeNode *t); //single rotation on a right node
    TreeNode* doubleLeft(TreeNode *t); //double rotation on a left node
    TreeNode* doubleRight(TreeNode *t); //double rotation on a right node
    bool IsThere(DataType x); //return true if x is in the tree, otherwise return false
    void Delete(DataType x); //if value x is in the list, remove x
    void Display(); // Display the data values in the list
    void Inorder(TreeNode* t); //Inorder Traversal 
    void Preorder(TreeNode* t); //Preorder Traversal
    void Postorder(TreeNode* t); //Postorder Traversal
    
private:
	TreeNode *root;
};

#endif	/* TREE_H */

