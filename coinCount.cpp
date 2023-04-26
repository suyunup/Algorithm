#include <iostream>
using namespace std;


int main(){

    
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int lencoinlist;
    int data;
    int mycoin;
    int answer =0;
    cin >> mycoin;


    cin >> lencoinlist;
    int coinlist[lencoinlist];
    for (int j = 0; j < lencoinlist; j++){
      cin >> data;
      coinlist[j] = data;
    }

    
    int dp[mycoin+1];
    for(int i = 0; i <=mycoin; i++){
        dp[i] =99999;
    }

    dp[0]=0;
    for(int i =0; i<lencoinlist; i++){
        for(int j =coinlist[i]; j<=mycoin; j++){
            dp[j] = min(dp[j], dp[j- coinlist[i]]+1);

        }
    }




    cout<<dp[mycoin] <<endl;




  }
  return 0;

}