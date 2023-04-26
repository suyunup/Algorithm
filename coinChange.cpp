#include <iostream>
using namespace std;


int main(){

  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
        int lencoinlist;
        int data;
        int mycoin;
        
        cin >> mycoin;

        int dp[20][10000] = {0};
        dp[0][0] = 1;

        cin >> lencoinlist;
        int coinlist[lencoinlist];
        for (int j = 0; j < lencoinlist; j++){
            cin >> data;
            coinlist[j] = data;
        }
        
        for (int i = 1; i <= lencoinlist; i++)
        {
            for (int j = 0; j <= mycoin; j++)
            {
                if (j < coinlist[i-1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - coinlist[i-1]] + dp[i - 1][j];
            }
        }
        cout << dp[lencoinlist][mycoin]<<"\n";
    }

  return 0;

}