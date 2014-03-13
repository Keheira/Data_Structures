#include "avlTree.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    avlTree a;
    int x,y;
    
    while(true){
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display Balanced AVL Tree"<<endl;
        cout<<"3.InOrder traversal"<<endl;
        cout<<"4.PreOrder traversal"<<endl;
        cout<<"5.PostOrder traversal"<<endl;
        cin>>x;

        if(x == 1){
            cout<<"Enter value to be inserted: ";
            cin>>y;
            a.root = a.insert(a.root, y);
            cout<<endl;
        }

        else if (x == 2){
            if (a.root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            a.display(a.root, 1);
            cout<<endl;
        }

        else if (x == 3){
            cout<<"Inorder Traversal:"<<endl;
            a.inorder(a.root);
            cout<<endl;
        }

        else if (x == 4){
            cout<<"Preorder Traversal:"<<endl;
            a.preorder(a.root);
            cout<<endl;;
        }
        
        if(x == 5){
            cout<<"Postorder Traversal:"<<endl;
            a.postorder(a.root);    
            cout<<endl;
        }
    }
        
    return 0;
}
