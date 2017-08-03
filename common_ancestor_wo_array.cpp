/*
08/03/2017
Common ancestor wo using arrays
- Go down from ROOT to the node
- Keep go left and right.
- If left and right reach the value n1 & n2 at the same time, return root.
- If one of the node reach first, then return the root of this node.

Caution:
return leaf careful otherwise, segmentation fault because it points to NULL
 */
#include<iostream>
using namespace std;


struct node
{
  int data;
  node *left;
  node *right;
};
node *create_node(int value)
{
  node *tmp = new node;
  tmp->data = value;
  tmp->left = NULL;
  tmp->right = NULL;
  return tmp;
}
node *findLCA(node*,int,int);
int main()
{
  node *root = NULL;
  root = create_node(23);
  root->left = create_node(12);
  root->right = create_node(2);
  root->left->left = create_node(3);
  root->left->right = create_node(15);
  root->left->left->right = create_node(1);
  root->left->right->left = create_node(9);

  root->right->right =  create_node(1);
  root->right->left =  create_node(7);

  node *ancestor;
  ancestor = findLCA(root, 3,15);
  cout<<ancestor->data<<endl;
}

node *findLCA(node *root1, int val1, int val2)
{
  if(root1 == NULL)
    return NULL;

  if(root1->data == val1 || root1->data == val2)
    return root1;

  node *findLeft  = findLCA(root1->left, val1, val2);
  node *findRight = findLCA(root1->right, val1, val2);
  if( findLeft!= NULL && findRight!= NULL)
    return root1;
  
  return ( (findLeft!=NULL) ? findLeft : findRight);
}
