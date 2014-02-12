#include <iostream> 
#include <fstream>
#include <cstdlib>
#include <queue>

using namespace std;

typedef
struct
{
	int outdegree, *adjList;
} outd;

outd * G;
int numNodes;

/*
typedef
struct
{
	int key,
	    indegree;
} ind;
*/

void topologicalSort(int n)
{
	int i,		// node index
	    j;		// local adjList index
	int outDegree;	// out degree of current node
	int *adjList;	// locally allocated dynamic array
	int inDegree[n];
	//ind inDegree[n];
	for (int k = 0; k < n; k++)
	{
		inDegree[k] = 0;
		//inDegree[k].key = k;
		//inDegree[k].indegree = 0;
	}

	for (i = 0; i < n; i++)
	{
		outDegree = G[i].outdegree;
		adjList = G[i].adjList;
		for (j=0; j < outDegree; j++)
			inDegree[adjList[j]]++;
			//inDegree[adjList[j]].indegree++;
	}

	/*

	Repeat the following steps until the graph is empty:

	1. Select a vertex that has in-degree zero.
	2. Add the vertex to the sort.
	3. Delete the vertex and all the edges emanating from it from the graph.
	
	*/

	for (int k = 0; k < n; k++)
		cout << "inDegree[" << k << "] = " << inDegree[k] << endl;
		//cout << "inDegree[" << k << "] = " << inDegree[k].indegree << endl;
}

void printStack(int i)
{
	cout << "stack=[" << i << "], node selected = " << i << ", topOrder-array = [" << i << "]" << endl; 
}

void cleanup(outd node[], int n)
{
        for (int i = 0; i < n; i++)
        {
                delete [] node[i].adjList;
				node[i].adjList = NULL;
        }
}

void readDigraph()
{
	cout << "Reading digraph..." << endl;
	ifstream inFile("digraph.dat");
	//int numNodes;
	int adegree;
	int index;
	int odegree;
	
	if (!inFile)
	{
		cout << "Error opening file" << endl;
		exit(1);
	}

	cout << "Reading numNodes" << endl;
	inFile >> numNodes;
	//inFile.ignore(255, '\n');
	//outd G[numNodes];
	G = new outd[numNodes];
	cout << numNodes << endl;
	int count = 0;
	while (count < numNodes)
	{
		inFile >> index;
		cout << "index = " << index << endl;
		char temp = inFile.get();
		temp = inFile.get(); // skip lparen
		temp = inFile.get();	// get outdegree

		odegree = temp - '0'; // convert from char to int (ASCII)
		G[index].outdegree = odegree;

		temp =  inFile.get(); // skip rparen
		cout << "outdegree = " << odegree << endl;

		// initialize dynamic adjacency matrix
		G[index].adjList = new int[odegree];

		int count2 = 0;
		// get adjacent G
		while (count2 < odegree)
		{
			inFile >> adegree;
			//cout << "adegree[" << count2 << "] = " << adegree << endl;
			G[index].adjList[count2] = adegree;
			cout << "G[" << index << "].adjList[";
			cout << count2 << "] = ";
			cout << G[index].adjList[count2] << endl;
			count2++;
		}
		count++;
	}
}

int main()
{
	readDigraph();
	topologicalSort(numNodes);
	cleanup(G, numNodes);
	return 0;
}
