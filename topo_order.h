#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

#ifndef TOPO_H
#define TOPO_H

class TopoOrder
{
  public:
    class Node
    {
      public:
        friend class TopoOrder;
        int inDegree,
            outDegree,
            adjNodes[];
        Node();
        Node(int cOutDegree);
    };
    TopoOrder();
    TopoOrder(std::string datafile);
  private:
    int numNodes;
    Node *nodes;
    int topoOrder[];

    void readDigraphAndComputeIndegrees(std::string datafile);
    void computeTopoOrder();
    void printOutDegree();
    void printInDegree();
};

#endif
