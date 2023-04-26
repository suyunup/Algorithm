#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bp[101][101];

int cut(int l, int r, int cutting[])
{
    int& newbp = bp[l][r];
    
    if (newbp == -1){
        newbp = 0;
        for (int i = l + 1; i < r; i++){
            if (newbp == 0){
                newbp = cut(l, i, cutting) + cut(i, r, cutting) + cutting[r] - cutting[l];
            }else{
                newbp = min(newbp, cut(l, i, cutting) + cut(i, r, cutting) + cutting[r] - cutting[l]);
            }
        }
    }
    return newbp;
}

int main(){
    int numTestCases;
    cin >> numTestCases;

    for(int i = 0; i < numTestCases; i++){
        int sizeCutting;
        int lenCutting;

        cin>> sizeCutting;
        cin >> lenCutting;
        
        for (int k = 0; k < 101; k++){
            for (int j = 0; j < 101; j++){
                bp[k][j] = -1;
            }
        }
        
        int cutting[lenCutting + 2];
        cutting[0] = 0;
        for (int k = 1; k <= lenCutting; k++){
            cin >> cutting[k];
        }
        cutting[lenCutting + 1] = sizeCutting;
        
        cout << cut(0, lenCutting +1, cutting) << "\n";
    }

    return 0;
}