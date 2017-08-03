/*
08/03/2017
Common ancestor
- Go down from ROOT to the node, put data into 2 arrays
- Compare 2 arrays, when they start to be different, then it is the common node ROOT.
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> path1, path2;
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
bool findPath(node*,vector<int> &,int);
int findLCA(node*,int,int);
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


  cout<<findLCA(root,3,15)<<endl;

}
bool findPath(node *root1, vector<int> &path, int val)
{
  if(root1 == NULL)
    return false;
  path.push_back(root1->data);
  //  cout<<"inside find path "<<root1->data<<endl;
  if(root1->data == val)
    return true;
  if(findPath(root1->left,path, val) || findPath(root1->right,path, val))
    return true;
  path.pop_back();
  return false;
}
int findLCA(node *root1, int val1, int val2)
{
  if( !findPath(root1, path1, val1) ||  !findPath(root1, path2, val2) )
    return -1;
  
  int longPath = (path1.size()>path2.size()) ? path1.size() : path2.size();
  cout<<"Long path is= "<<longPath<<endl;
  int i;
  for(i=0; i<longPath; i++)
    {
      //      cout<<path1[i]<<" path2= "<<path2[i]<<endl;
      if(path1[i] != path2[i])
      break;
    }
  return path1[i-1];
}
