/*
주어진 초기 코드는 입력을 정렬할 때 정수 key 값을 16진수 자리수에 따라 radix sort 를 하는 코드이다. digit16() 함수를 활용하는 countingSort16() 함수를 작성하여 Radix sort 가 수행되도록 완성하라.
표준 출력으로부터의 입력은 다음과 같다.
첫번째 행에 데이터의 갯수 n 이 1과 1000000 사이의 정수로 주어진다.
두번째 행부터 n+1 번째 행에 정수(정수는 0과 1000000000 사이의 정수) 와 영어단어 (영어 단어는 satellite data임)의 쌍이 공백으로 구분되어 주어진다.
이 n 개의 데이터들을 정수에 대한 올림차순으로 stable 하게 정렬하여 표준 출력에 정수와 영어 단어의 쌍을 출력하게 된다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int digit16(int v, int d){
// 양의 정수 v 의 16진수 d 번째 숫자를 반환하는 함수
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 1 이라면 6 을 반환
// 예를 들어 v 의 값이 78320238 (= 0x04ab126e) 이고 d 가 4 라면 11 (= 0xb) 을 반환
  v = v >> d*4;
  return v & 0xf;
}

void countingSort16(vector<pair<int, string> >& v,int d){
    // cout<< " "<<endl;
    //d는 자리수
    //16진수로 변환했을때 같은 자리수들 sort
    //누적합은 16진수를 저장
    //수열비는 정렬된 벡터를 저장
    vector<int,string> c;
    vector<int,string> b(v.size(), pair<int,string>(0,""));
    for(int i = 0; i < 16; i++){
        c.push_back(0,"");
    }
    for(int j = 0; j < v.size(); j++){//각 자리수는 0~15(F)사이임
        int digitresult = digit16(v[j].first, d);
        c[digitresult] = c[digitresult] + 1; 
    }
    
    for(int i = 1; i < 16; i++){//누적합
        c[i] = c[i] + c[i-1];
    }
    for(int j = v.size()-1; j>=0; j--){
        int digitresult = digit16(v[j].first, d);
        b[c[digitresult]] = digitresult;
        c[digitresult] = c[digitresult] - 1;
    }
    
    
    
    cout<<"c:";
    for (int i=0; i<c.size(); i++){
        cout << c[i] << ' ' << endl;
    }
    
}

int main(void) {
    int n;
    vector<pair<int, string> > v;
    cin >> n;
    for (int i=0; i<n; i++){
        int d;
        string s;
        cin >> d >> s;
        v.push_back(pair<int,string>(d,s));
    }
    //radixsort
    for (int d=0; d<8; d++) countingSort16(v, d);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }
    return 0;
}