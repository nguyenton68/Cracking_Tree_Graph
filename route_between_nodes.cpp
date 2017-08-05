/*
Check is there a way from a vertex src to vertex dst
- Use a queue to keep track of visited vertex, after visited it, remove it from the queue
- Loop through the dimension of 2D array, which contain the edges (directed edges).

- If there is a path and the node have not been visited yet,
- Push into queue the second index which a[indx1][indx2] != 0, mean there is a path. Mark visited[indx2] = true, mean that visit this vertex already.
- Next, we visit this indx2.

+ this code use input file connection.dat which store the edges.
 */
#include<iostream>
#include<queue>
#include<fstream>
using namespace std;

const int N=8;
queue<int> q;
int g[N][N];
bool visited[N];
void init()
{
  memset(g, 0, sizeof(g));
  memset(visited, 0, sizeof(visited)); 
}
bool route(int src, int dst)
{
  q.push(src);
  visited[src]=true;
  while( !q.empty())
    {
      int t= q.front();
      q.pop();
      if(t == dst)
	return true;
      for(int i=0; i<N; i++)
	{	 
	  if(g[t][i] && !visited[i])
	    {
	      visited[i] = true;
	      q.push(i);
	    }
	}
    }
  return false;
}
int main()
{
  ifstream data("connection.dat",ios_base::in);
  //  init();
  int row, column;
  while(!data.eof())
    {
      data>>row>>column;
      g[row][column] = true;
    }
  bool res=  route(0,6);
  cout<<"Result= "<<res<<endl;
}
