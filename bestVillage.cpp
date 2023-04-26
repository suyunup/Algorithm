#include <iostream>
#include <vector>
using namespace std;

int N;
int dp[10001][2];
int villageNum[10001];
bool visited[10001];
vector<int> tr[10001];


void find(int now){
 visited[now] = true;

 for(int i =0; i < tr[now].size(); i++){
   int next = tr[now][i];
   if(visited[next]){
     continue;
   }
   find(next);

   dp[now][0] += max(dp[next][0] , dp[next][1]);
   dp[now][1] += dp[next][0];
 }
}





int main(){
 int N;
 cin >>N;

 for(int i = 1; i <=N; i++){
   cin >> villageNum[i];
 }
 for(int i =0; i <N-1; i++){
   int a, b;
   cin >> a;
   cin >> b;
   tr[a].push_back(b);
   tr[b].push_back(a);
 }

 for(int i=1;i<=N; i++){
   dp[i][0] = 0;
   dp[i][1] = villageNum[i];
}
 find(1);
 cout<< max(dp[1][0], dp[1][1]);

 return 0;

}
