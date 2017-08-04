/*
Find is a tree a subtree of another big tree
- For NULL pointer, replace with 'x'
- Then use pre-order transverse, put into a string every node
- Compare 2 strings, if s2 is a substring of s1.

Caution:
pass the string by reference: string &
 */
#include<iostream>
#include<string>
using namespace std;

struct node
{
  string data;
  node *left, *right;
};
node *create_node(string);
void getString(node*,string&);

int main()
{
  node *root0, *root1;
  root0 = create_node("1");
  root0->left = create_node("2");
  root0->right = create_node("3");
  root0->left->left = create_node("4");

  root1 = create_node("2");
  root1->left = create_node("4");

  string s1;
  string s2;

  getString(root0,s1);
  getString(root1,s2);

  cout<<s1<<endl;
  cout<<s2<<endl;

  if(s1.find(s2))
    cout<<"is a subtree"<<endl;
  else
    cout<<"is not a subtree"<<endl;
}
node *create_node(string s)
{
  node *tmp = new node;
  tmp->left = NULL;
  tmp->right = NULL;
  tmp->data = s;

  return tmp;
}
void getString(node *root, string &s)
{
  if(root != NULL)
    {
      s.append(root->data);
      getString(root->left, s);
      getString(root->right, s);
    }
  else
    s.append("x");
}
