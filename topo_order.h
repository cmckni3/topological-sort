#include <iostream>
#include <fstream>
#include <string>

#define DEBUG if(false)

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
            *adjNodes;
        Node();
        Node(int odegree);
        ~Node();
    };
    TopoOrder();
    TopoOrder(std::string datafile);
    ~TopoOrder();
  private:
    int numNodes;
    int topoCount;
    Node *nodes;
    int *topoOrder;

    void readDigraphAndComputeIndegrees(std::string datafile);
    void computeTopoOrder();
    void printNodes();
    void printOutDegree();
    void printInDegree();
    void printTopoOrder();
};

#endif
