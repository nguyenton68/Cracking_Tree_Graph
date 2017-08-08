/*
Sum of a path to a given value
- Go through all nodes.
- Check the sum from bottom node to the root
 */
#include<iostream>
#include<string>
using namespace std;
const int N = 9;
int *path = new int[N];
struct node
{
  int data;
  node *left, *right;
};
node *create_node(int);
void sumPath(node*, int*, int, int);
int main()
{
  node *root;
  root = create_node(5);
  root->left = create_node(2);
  root->right = create_node(7);
  root->left->left = create_node(1);
  root->left->right = create_node(3);
  root->left->right->right = create_node(4);
  root->right->left = create_node(6);
  root->right->right = create_node(8);
  root->right->right->right = create_node(9);

  sumPath(root, path, 7,0);
}
node *create_node(int s)
{
  node *tmp = new node;
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->data = s;

  return tmp;
}
void sumPath(node* root, int *path, int sum, int level)
{
  if(root == NULL)
    return;
  path[level] = root->data;
  int s=0;
  for( int i=level; i>=0; i--)
    {
      s += path[i];
      if(s==sum)
	{
	  for(int j=level; j>=i; j--)
	    {
	      cout<<"-->"<<path[j];
	    }
	  cout<<endl;
	}
    }
  sumPath(root->left, path, sum, level+1);
  sumPath(root->right, path, sum, level+1);
}
