#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include "topo_order.h"

using namespace std;

// void printStack(int i)
// {
//   cout << "stack=[" << i << "], node selected = " << i << ", topOrder-array = [" << i << "]" << endl;
// }

// void cleanup(outd node[], int n)
// {
//   for (int i = 0; i < n; i++)
//   {
//           delete [] node[i].adjList;
//   node[i].adjList = NULL;
//   }
// }

int main()
{
  TopoOrder topo = TopoOrder("digraph.dat");
  // topologicalSort(numNodes);
  // cleanup(G, numNodes);
  return 0;
}
