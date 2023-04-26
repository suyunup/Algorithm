#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
	int s, e;
	int distance;
	Edge(int a, int b, int dist)
	{
		s = a;
		e = b;
		distance = dist;
	}
	bool operator < ( Edge &edge )
	{
		return distance < edge.distance;
	}
};
int getParent(int d[], int x)
{
	if(d[x] == x)
		return x;
	return d[x] = getParent(d, d[x]);	
}
void unionParent(int d[], int a, int b)
{
	a = getParent(d, a);
	b = getParent(d, b);

	if( a < b) d[b] = a;
	else d[a] = b;
}

bool findParent(int d[], int a, int b)
{
	a = getParent(d, a);
	b = getParent(d, b);

	if(a == b)
		return true;
	return false;
}

int main()
{
	int numTestCases;
    cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){


    int NODECOUNT;
    cin >>NODECOUNT;
    int Node[NODECOUNT + 1];
    int baseNode;
    vector<Edge> v;
    for(int j = 0; j < NODECOUNT; j++){
        int connectNodeNumber;
        cin >>baseNode;
        cin>>connectNodeNumber;
        for(int k = 0; k <connectNodeNumber; k++){
            int anotherNode;
            int weight;
            cin >> anotherNode;
            cin >> weight;
            v.push_back(Edge(baseNode,anotherNode,weight));
        }
    }


	sort(v.begin(), v.end());
	
	// 각 정점을 자기 자신으로 임시 설정
	for(int i=1;i<=NODECOUNT;i++)
	{
		Node[i] = i;
	}

	int total = 0;
	for(int i=0;i<(int)v.size();i++)
	{
		if(!findParent(Node, v[i].s , v[i].e))
		{
			total += v[i].distance;
			unionParent(Node, v[i].s, v[i].e);
		}
	}

	v.clear();

	cout<<total<<"\n";

  }
	return 0;
}
