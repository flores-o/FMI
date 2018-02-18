#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node
{
  string data;
  node* left;
  node* right;
};
 node* newNode(string data)
{
  node* nod = new node;
  nod->data = data;
  nod->left = NULL;
  nod->right = NULL;

  return(nod);
}

void buildTree( vector<string> pre, node * & root)
{
  static int preIndex = 0;

  if(preIndex==pre.size()) return ;
  if(pre[preIndex].compare("null")==0)
  {
     preIndex++;
     return ;

  }


   root = newNode(pre[preIndex++]);


   buildTree(pre,root->left);
   buildTree(pre ,root->right);

}
void printInorder(node* nod)
{
  if (nod == NULL)
     return;

  /* first recur on left child */
  printInorder(nod->left);

  /* then print the data of node */
  cout<< nod->data<<" ";

  /* now recur on right child */
  printInorder(nod->right);
}
bool isBST(node* root, node* l=NULL, node* r=NULL)
{
    // Base condition
    if (root == NULL)
        return true;

    // if left node exist that check it has
    // correct data or not
    if (l != NULL and root->data < l->data)
        return false;

    // if right node exist that check it has
    // correct data or not
    if (r != NULL and root->data > r->data)
        return false;

    // check recursively for every node.
    return isBST(root->left, l, root) and
           isBST(root->right, root, r);
}
int main()
{
    vector<string> pre={"4", "1", "null", "3", "null" ,"null", "7", "6" ,"null" ,"null" ,"null" };


    node* root ;
    buildTree(pre,root);

   // printInorder(root);
   if(isBST(root))
      cout<<"este BST"<<endl;
   else
      cout<<"nu este BST"<<endl;
    return 0;
}
