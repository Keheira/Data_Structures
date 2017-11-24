/* 
 * File:   avlTree.h
 * Author: keheira
 *
 * Created on December 4, 2013, 6:54 PM
 */

#ifndef AVLTREE_H
#define	AVLTREE_H

struct avl_node

{

    int data;

    struct avl_node *left;

    struct avl_node *right;

};

 

/*

 * Class Declaration

 */

class avlTree

{

    public:

        avlTree();
        
        int height(avl_node *); //keep track of tree height

        int diff(avl_node *); //height difference

        avl_node *rr_rotation(avl_node *); //right single rotation

        avl_node *ll_rotation(avl_node *); //left single rotation

        avl_node *lr_rotation(avl_node *); //right double rotation

        avl_node *rl_rotation(avl_node *); //left double rotation

        avl_node* balance(avl_node *); 

        avl_node* insert(avl_node *, int ); //insert value in tree

        void display(avl_node *, int); //display tree

        void inorder(avl_node *); //2nd look

        void preorder(avl_node *); //1st look

        void postorder(avl_node *); //3rd look
        

    avl_node *root;

};

#endif	/* AVLTREE_H */

