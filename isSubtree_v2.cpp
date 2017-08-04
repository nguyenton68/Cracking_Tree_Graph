/*
Check if T2 is a subtree of T1
- Loop through T1 and check if any node == T2
- If yes, check all left and right node in each tree to see are they equal

Caution:
I did root1==NULL && root2==NULL in loopTree and it gave segmentation fault.
 */
#include<iostream>
using namespace std;
struct node
{
  node *left, *right;
  int data;
};
node *create_node(int);
bool matchTree(node *, node*);
bool loopTree(node *, node*);
int main()
{
  node *rootBig = create_node(1);
  rootBig->left = create_node(2);
  rootBig->right = create_node(3);
  rootBig->left->left = create_node(4);

  node *rootSmall = create_node(2);
  rootSmall->left = create_node(5);

  bool res = loopTree(rootBig, rootSmall);
  cout<<"Small is a subtree of Big tree or not T/F= "<<res<<endl;
}
node *create_node(int val)
{
  node *tmp = new node;
  tmp->data = val;
  tmp->left = NULL;
  tmp->right = NULL;

  return tmp;
}
bool matchTree(node *root1, node *root2)
{
  if(root1 == NULL && root2 == NULL)
    return true;
  else if(root1 == NULL || root2 == NULL)
    return false;
  else if(root1->data != root2->data)
    {
      return false;
    }
  else
    {
    return (matchTree(root1->left, root2->left) && 
	    matchTree(root1->right, root2->right)) ;  
    }
}
bool loopTree(node *root1, node *root2)
{
  if(root1 == NULL )//&& root2 == NULL)
    return false;// empty tree
  else if(root1->data == root2->data)
    {
      return matchTree(root1,root2);
    }
  else
    {
      return (loopTree(root1->left,root2) || loopTree(root1->right,root2));
    }
}
