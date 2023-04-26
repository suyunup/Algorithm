/******************************************
    해밍수
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int numTestCases;
  cin >> numTestCases;

  for (int i=0;i<numTestCases;i++){
    int number;
    cin >> number;

    vector<unsigned int> hamming;
      for (unsigned int i = 1;; i *= 2) {
        for (unsigned int j = i;; j *= 3) {
            for (unsigned int k = j;; k *= 5) {
                hamming.push_back(k);
                if (k > 4294967295 / 5) break;
            }
            if (j > 4294967295 / 3) break;
        }
        if (i > 4294967295 / 2) break;
    }

    sort(hamming.begin(), hamming.end());
    cout << hamming[numbker - 1] << endl;

  }

  return 0;
}
