// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct DisjointSet {
// 	vector<int> parent, rank;
// 	DisjointSet(int n) : parent(n), rank(n) {
// 		for (int i = 0; i < n; ++i){
// 			parent[i] = i;
//         }

// 	}
// 	int find(int x){
// 		if (x == parent[x]){
// 			return x;
//             }
// 		return parent[x] = find(parent[x]);
// 	}

// 	void merge(int u, int v){
// 		u = find(u), v = find(v);
// 		if (u == v){
//             return;
//             }
// 		if (rank[u] > rank[v]){
//             swap(u, v);
//             }
// 		parent[u] = v;
// 		if (rank[u] == rank[v]){
//             ++rank[v];
//             }
// 	}

// };

// const int MAX = 1000;
// int V;

// vector<pair<int, int>> adj[MAX];

// int kruskal(vector<pair<int, int>>& selected) {

// 	int ret = 0;

// 	selected.clear();
// 	vector<pair<int, pair<int, int>>> edges;

// 	for(int u =0; u< V; ++u)

// 		for (int i = 0; i < adj[u].size(); ++i) {

// 			int v = adj[u][i].first;
//             int cost = adj[u][i].second;

// 			edges.push_back(make_pair(cost, make_pair(u, v)));

// 		}

// 	sort(edges.begin(), edges.end());

// 	DisjointSet sets(V);
// 	for (int i = 0; i < edges.size(); ++i) {
// 		int cost = edges[i].first;
// 		int u = edges[i].second.first, v = edges[i].second.second;
// 		if (sets.find(u) == sets.find(v)) continue;
// 		sets.merge(u, v);
// 		selected.push_back(make_pair(u, v));
// 		ret += cost;

// 	}

// 	return ret;



// }



// int main(){
//     int numTestCases;
//     cin >> numTestCases;

//   for(int i = 0; i < numTestCases; i++){


	
//     cin >>V;//정점개수
//     int baseNode;
//     for(int j = 1; j <= V; j++){
//         int connectNodeNumber;
//         cin >>baseNode;
//         cout <<baseNode<<"시작\n";
//         cin>>connectNodeNumber;
//         cout <<connectNodeNumber<<"\n";
//         for(int k = 0; k <connectNodeNumber; k++){
//             cout <<k<<"반복시작\n";
//             int anotherNode;
//             int weight;
//             cin >> anotherNode;
//             cin >> weight;
//             adj[baseNode].push_back(make_pair(anotherNode, weight));
//             cout <<baseNode<<" "<<anotherNode<<" "<< weight<<"add.\n";

//         }
        
        


//     }



// 	vector<pair<int, int>> selected;

// 	int sum = kruskal(selected);

// 	cout << sum << endl;



// 	for (int i = 0; i < selected.size(); ++i) {

// 		cout << i+1 << "번째 연결 " << selected[i].first << " " << selected[i].second;

// 		cout << endl;
// 	}
//   }
//   return 0;

// }

////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 1e6-1;
int root[MAX];
const int nodes = 4, edges = 5;
pair <long long, pair<int, int> > p[MAX];

int parent(int a)                                                       //find the parent of the given node
{
    while(root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b)                                         //check if the given two vertices are in the same “union” or not
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

long long kruskal()
{
    int a, b;
    long long cost, minCost = 0;
    for(int i = 0 ; i < edges ; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;
        if(parent(a) != parent(b))                                  //only select edge if it does not create a cycle (ie the two nodes forming it have different root nodes)
        {
            minCost += cost;
            union_find(a, b);
        }
    }
    return minCost;
}

int main()
{
    int x, y;
    long long weight, cost, minCost;
    for(int i = 0;i < MAX;++i)                                       //initialize the array groups
    {
        root[i] = i;
    }

    int baseNode = 0;
    for(int j = 0; j < numberOfNodes; j++){
        int connectNodeNumber =0;
        cin >>baseNode;
        cin>>connectNodeNumber;
        for(int k = 0; k <connectNodeNumber; k++){
            int anotherNode;
            int weight;
            cin >> anotherNode;
            cin >> weight;
            myGraph->AddWeightToEdge(baseNode, anotherNode, weight);
            // cout <<baseNode<<" "<<anotherNode<<" "<< weight<<"add.\n";

        }
    }


    p[0] = make_pair(10, make_pair(0, 1));
    p[1] = make_pair(18, make_pair(1, 2));
    p[2] = make_pair(13, make_pair(2, 3));
    p[3] = make_pair(21, make_pair(0, 2));
    p[4] = make_pair(22, make_pair(1, 3));
    sort(p, p + edges);                                             //sort the array of edges
    minCost = kruskal();
    cout << "Minimum cost is: "<< minCost << endl;
    return 0;
}


/////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edgePair pair<int,int>

class Graph
{
    private:
        vector<pair<int, edgePair>> MyGraph;
        vector<pair<int, edgePair>> minSpanTree;
        int *parent;
        int nodes;
    public:
        Graph(int nodes);
        void AddWeightToEdge(int firstNode, int secondNode, int weight);
        int findSet(int i);
        void unionSet(int i, int j);
        void kruskalMinSpanTree();
        void printMinSpanTree();
};

Graph::Graph(int nodes)
{
    MyGraph.clear();
    minSpanTree.clear();
    parent = new int[nodes];
    for (int i = 0; i < nodes; i++)
    {
        parent[i] = i;
    }
    MyGraph.clear();
    minSpanTree.clear();
    
}

void Graph::AddWeightToEdge(int firstNode, int secondNode, int weight)
{
    MyGraph.push_back(make_pair(weight, edgePair(firstNode, secondNode)));
}

int Graph::findSet(int i)
{
    if (i == parent[i])
    {
        return i;
    }
    else
    {
       return findSet(parent[i]);
    }
}

void Graph::unionSet(int i, int j)
{
    parent[i] = parent[j];
}

void Graph::kruskalMinSpanTree()
{
    int i, firstValue, secondValue;
    sort(MyGraph.begin(), MyGraph.end());
    for (i = 0; i < MyGraph.size(); i++)
    {
        firstValue = findSet(MyGraph[i].second.first);
        secondValue = findSet(MyGraph[i].second.second);
        if (firstValue != secondValue)
        {
            minSpanTree.push_back(MyGraph[i]);
            unionSet(firstValue, secondValue);
        }
    }
}

void Graph::printMinSpanTree()
{
    int sum = 0;
    for (int i = 0; i < minSpanTree.size(); i++)
    {
        sum += minSpanTree[i].first;
        
    }
    cout<<sum<< "\n";
}
int main()
{
    int numTestCases;
    cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int numberOfNodes;
    cin >>numberOfNodes;//정점개수
    Graph *myGraph= new Graph(numberOfNodes);



    int baseNode = 0;
    for(int j = 0; j < numberOfNodes; j++){
        int connectNodeNumber =0;
        cin >>baseNode;
        cin>>connectNodeNumber;
        for(int k = 0; k <connectNodeNumber; k++){
            int anotherNode;
            int weight;
            cin >> anotherNode;
            cin >> weight;
            myGraph->AddWeightToEdge(baseNode, anotherNode, weight);
            // cout <<baseNode<<" "<<anotherNode<<" "<< weight<<"add.\n";

        }
    }
    

    myGraph->kruskalMinSpanTree();
    myGraph->printMinSpanTree();
    myGraph->~Graph();
  }
    // return 0;
}

// myGraph.AddWeightToEdge(0, 1, 1);
    // myGraph.AddWeightToEdge(0, 4, 4);

    // myGraph.AddWeightToEdge(1, 0, 1);
    // myGraph.AddWeightToEdge(1, 2, 7);
    // myGraph.AddWeightToEdge(1, 4, 3);

    // myGraph.AddWeightToEdge(2, 1, 7);
    // myGraph.AddWeightToEdge(2, 3, 9);
    // myGraph.AddWeightToEdge(2, 4, 5);

    // myGraph.AddWeightToEdge(3, 2, 9);
    // myGraph.AddWeightToEdge(3, 4, 2);

    // myGraph.AddWeightToEdge(4, 0, 4);
    // myGraph.AddWeightToEdge(4, 1, 3);
    // myGraph.AddWeightToEdge(4, 2, 5);
    // myGraph.AddWeightToEdge(4, 3, 2);

    /*
    0 2 1 1 4 4
    1 3 0 1 2 7 4 3
    2 3 1 7 3 9 4 5
    3 2 2 9 4 2
    4 4 0 4 1 3 2 5 3 2


    */