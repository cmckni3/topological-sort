#include "topo_order.h"

TopoOrder::Node::Node()
{
}

TopoOrder::Node::~Node()
{
  delete adjNodes;
}

TopoOrder::TopoOrder()
{
}

TopoOrder::TopoOrder(std::string datafile)
{
  topoCount = 0;
  readDigraphAndComputeIndegrees(datafile);
  DEBUG printNodes();
  DEBUG cout << "-------------------------------------------------" << endl;
  DEBUG cout << "                  Out degree" << endl;
  DEBUG printOutDegree();
  DEBUG cout << "-------------------------------------------------" << endl;
  DEBUG cout << "                  In degree" << endl;
  DEBUG printInDegree();
  DEBUG cout << "-------------------------------------------------" << endl;
  computeTopoOrder();
  printTopoOrder();
}

TopoOrder::~TopoOrder()
{
  // delete nodes;
  delete topoOrder;
}

void TopoOrder::readDigraphAndComputeIndegrees(std::string datafile)
{
  ifstream inFile(datafile);

  if (!inFile)
  {
    cout << "Error opening file: " << datafile << endl;
    exit(1);
  }

  inFile >> numNodes;
  nodes = new Node[numNodes];
  topoOrder = new int[numNodes];
  for (int i = 0; i < numNodes; i++)
  {
    int index;
    int odegree;
    char temp;
    inFile >> index;
    inFile >> temp; // skip lparen
    inFile >> odegree;  // get outdegree
    inFile >> temp; // skip rparen

    nodes[index] = Node();
    nodes[index].outDegree = odegree;
    nodes[index].inDegree = 0;
    nodes[index].adjNodes = new int[odegree];

    // Read edges
    for (int j = 0; j < odegree; j++)
    {
      int adegree;
      inFile >> adegree;
      nodes[index].adjNodes[j] = adegree;
    }
  }
  for (int i = 0; i < numNodes; i++)
  {
    int outdegree = nodes[i].outDegree;
    for (int j = 0; j < outdegree; j++)
    {
      DEBUG cout << "Incrementing " << nodes[i].adjNodes[j] << endl;
      int adjNode = nodes[i].adjNodes[j];
      nodes[adjNode].inDegree++;
    }
  }
}

void TopoOrder::printNodes()
{
  for (int i = 0; i < numNodes; i++)
  {
    cout << i << " " << nodes[i].outDegree << " ";
    for (int j = 0; j < nodes[i].outDegree; j++)
    {
      cout << nodes[i].adjNodes[j] << " ";
    }

    cout << endl;
  }
}

void TopoOrder::printOutDegree()
{
  for (int i = 0; i < numNodes; i++)
  {
    cout << nodes[i].outDegree << endl;
  }
}

void TopoOrder::printInDegree()
{
  for (int i = 0; i < numNodes; i++)
  {
    cout << nodes[i].inDegree << endl;
  }
}

void TopoOrder::printTopoOrder()
{
  for (int i = 0; i < numNodes; i++)
  {
    cout << topoOrder[i] << " ";
  }
  cout << endl;
}

void TopoOrder::computeTopoOrder()
{
  cout << "inDegrees = [";
  for (int j = 0; j < numNodes; j++)
  {
    cout << nodes[j].inDegree << " ";
  }
  cout << "]" << endl;
  int stack[numNodes];
  int stackSize = 0;
  // push inDegree = 0 nodes onto stack
  for (int j = 0; j < numNodes; j++)
  {
    if (nodes[j].inDegree == 0)
    {
      stack[stackSize++] = j;
    }
  }

  cout << "Nodes with inDegree 0 [";
  for (int j = 0; j < stackSize; j++)
  {
    cout << stack[j] << ", ";
  }
  cout << "]" << endl;

  while (stackSize > 0)
  {
    // root node index
    int index = stack[--stackSize];
    // pop
    Node root = nodes[index];
    topoOrder[topoCount++] = index;

    for (int k = 0; k < root.outDegree; k++)
    {
      Node *adjNode = &nodes[root.adjNodes[k]];
      adjNode->inDegree--;
      if (adjNode->inDegree == 0)
      {
        stack[stackSize++] = root.adjNodes[k];
      }
    }
    cout << "reduced inDegrees = [";
    for (int j = 0; j < numNodes; j++)
    {
      cout << nodes[j].inDegree << " ";
    }
    cout << "]" << endl;
  }
}
