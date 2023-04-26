#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF	 99999


struct Edge{
	int start;
	int end;
	int distance;

	Edge(int v1, int v2, int dist)
	{
		start		= v1;
		end			= v2;
		distance	= dist;
	}
};

class Graph{

public:
	// 전체 노드
	vector<int> nodes;

	// 전체 간선
	vector<Edge> edges;

	// 현재 노드에 연결된 인접 노드와 간선의 모든 정보 반환
	vector<pair<int, Edge>> getNodes(int u)
	{
		vector<pair<int, Edge>> res;

		vector<Edge>::iterator it;
		for (it =edges.begin(); it !=edges.end(); it++)
		{
			// 현재 노드가 시작점이면 종점을 간선 distance로 설정
			if(it->start == u)
			{
				res.push_back(make_pair(it->end, *it));
			}
			// 현재 노드가 종점이면, 시작점을 간선 distance로 설정
			else if(it->end == u)
			{
				res.push_back(make_pair(it->start, *it));
			}
		}
		return res;
	}

	void clear()
	{
		nodes.clear();
		edges.clear();
	}
};

void prim(Graph &g)
{
	unordered_map<int, int> NodeParent;	
	unordered_map<int, int> PARENT;
	unordered_map<int, int> DIST;

	vector<int>::iterator it;
	for(it = g.nodes.begin(); it !=g.nodes.end(); it++)
	{
		// 초기 부모노드 -1 설정
		PARENT[(*it)] = -1;
		// 초기 distance 무한대 설정
		DIST[(*it)] = INF;
	}

	// 1번 노드의 distance는 0
	DIST[1] = 0;
	// 모든 Node 순회를 위해 Queue로 설정
	vector<int> Q = g.nodes;

	while( !Q.empty())
	{
		// 람다함수, 전체노드에서 distance가 제일 작은 노드를 반환. min_element는 주소를 반환하기 때문에 포인터로 값을 받아와야 함.
		int u = *min_element(Q.begin(), Q.end(), 
			[&](char x, char y) {return DIST[x] < DIST[y];});

		// 실제 데이터를 찾아 지우고
		it = remove(Q.begin(), Q.end(), u);
		// 벡터 요소를 지운다.
		Q.erase(it, Q.end());

		// Parent가 있으면
		if(PARENT[u] != -1)
			NodeParent[u] = PARENT[u];

		vector<pair<int, Edge>>::iterator it2;
		vector<pair<int, Edge>> adj = g.getNodes(u);
		
		//현재 노드에 연결된 인접 노드를 찾는다
		for(it2 = adj.begin(); it2 !=adj.end(); it2++)
		{
			// 큐에 해당 노드가 존재하면, cycle 방지
			if(find(Q.begin(), Q.end(), it2->first) != Q.end())
			{
				// 현재 노드의 Edge가 최단 거리이면, 부모노드 업데이트 및 인접노드에 최단거리 설정
				if(it2->second.distance < DIST[it2->first])
				{
					PARENT[it2->first] = u;
					DIST[it2->first] = it2->second.distance;
				}
			}
		}

		adj.clear();
	}

	unordered_map<int, int>::iterator it3;
	for( it3 = NodeParent.begin(); it3 !=NodeParent.end(); it3++)
	{
		cout<<"Parent["<<it3->first<<"]: "<<it3->second<<endl;
	}
	cout<<endl;

	long long int total = 0;
	unordered_map<int, int>::iterator it4;
	for( it4 = DIST.begin(); it4 !=DIST.end(); it4++)
	{
		cout<<"Node["<<it4->first<<"], Distance:"<<it4->second<<endl;
		total += it4->second;
	}

	cout<<endl<<"total distance: "<<total<<endl;

	NodeParent.clear();
	PARENT.clear();
	DIST.clear();
}

void solve()
{
	Graph g;
	int Nodes[] = {1,2,3,4,5,6,7};
	g.nodes = vector<int>(Nodes, Nodes+sizeof(Nodes)/sizeof(Nodes[0]));

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
            g.edges.push_back(Edge(baseNode,anotherNode,weight));
        }
    }

	g.edges.push_back(Edge(1, 2, 9));
	g.edges.push_back(Edge(1, 3, 12));
	g.edges.push_back(Edge(1, 4, 5));
	g.edges.push_back(Edge(1, 5, 35));
	g.edges.push_back(Edge(2, 4, 14));
	g.edges.push_back(Edge(2, 5, 17));
	g.edges.push_back(Edge(3, 4, 10));
	g.edges.push_back(Edge(3, 6, 23));
	g.edges.push_back(Edge(3, 7, 53));
	g.edges.push_back(Edge(4, 5, 20));
	g.edges.push_back(Edge(4, 6, 19));
	g.edges.push_back(Edge(5, 6, 47));
	g.edges.push_back(Edge(5, 7, 32));
	g.edges.push_back(Edge(6, 7, 37));

	prim(g);

	g.clear();
}

int main()
{
	solve();
	return 0;
}


/*
3
10
1 3 2 9 3 8 4 5
2 3 1 9 5 7 6 9
3 5 1 8 4 3 5 2 7 3 8 5
4 3 1 5 3 3 8 7
5 4 2 7 3 2 6 5 7 4
6 5 2 9 5 5 7 6 9 9 10 8
7 5 3 3 5 4 6 6 8 4 9 7
8 4 3 5 4 7 7 4 9 4
9 4 6 9 7 7 8 4 10 3
10 2 6 8 9 3


5
1 3 2 1 4 8 5 5
2 2 1 1 3 6
3 1 2 6
4 1 1 8
5 1 1 5


5
1 4 2 20 3 12 4 12 5 8
2 3 1 20 3 17 4 5
3 3 1 12 2 17 5 6
4 3 1 12 2 5 5 5
5 3 1 8 3 6 4 5

*/