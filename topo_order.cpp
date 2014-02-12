#include "topo_order.h"

TopoOrder::Node::Node()
{
}

TopoOrder::Node::Node(int cOutDegree)
{
  outDegree = cOutDegree;
}

TopoOrder::TopoOrder()
{
}

TopoOrder::TopoOrder(std::string datafile)
{
  readDigraphAndComputeIndegrees(datafile);
  cout << "-------------------------------------------------" << endl;
  cout << "                  Out degree" << endl;
  printOutDegree();
  cout << "-------------------------------------------------" << endl;
  computeTopoOrder();
  cout << "-------------------------------------------------" << endl;
  cout << "                  In degree" << endl;
  printInDegree();
  cout << "-------------------------------------------------" << endl;
}

void TopoOrder::readDigraphAndComputeIndegrees(std::string datafile)
{
  ifstream inFile(datafile);
  int adegree;
  int index;
  int odegree;

  if (!inFile)
  {
    cout << "Error opening file: " << datafile << endl;
    exit(1);
  }

  inFile >> numNodes;
  for (int i = 0; i < numNodes; i++)
  {
    inFile >> index;
    char temp = inFile.get();
    temp = inFile.get(); // skip lparen
    temp = inFile.get();  // get outdegree

    odegree = temp - '0'; // convert from char to int (ASCII)

    temp =  inFile.get(); // skip rparen

    nodes[index] = Node(odegree);

    for (int j = 0; j < odegree; j++)
    {
      inFile >> adegree;
      nodes[index].adjNodes[j] = adegree;
    }
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

void TopoOrder::computeTopoOrder()
{
}
