#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

vector<pair<int, string> > L;
vector<pair<int, string> > R;

void merge(vector<pair<int,string> >& v, int p, int q, int r){
    int n = q - p + 1;
    int m = r - q;
    cout<<"test"<<endl;
    cout<<"n-2:"<<n-2<<endl;
    
    for(int i = 0; i<n-1; i++){
        L.push_back(v[p + i -2]);
        cout<<"i:"<<i<<endl;
    }
    for(int j = 0; j<m-1; j++){
        R.push_back(v[q +j-1]);
    }
    
    L.push_back(pair<int,string>(9999,"t"));
    R.push_back(pair<int,string>(9999,"t"));
      
    int i = 0;
    int j = 0;
    for(int k = p; p<r; p++){
        if(L[i] <= R[j]){
            v[k] = L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
    }
    
}
void mergesort(vector<pair<int, string> >& v, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(v,p,q);
        mergesort(v,q+1,r);
        merge(v,p,q,r);
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

    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}


/////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

vector<pair<int, string> > L;
vector<pair<int, string> > R;

void merge(vector<pair<int,string> >& v, int p, int q, int r){
    int n = q - p + 1;
    int m = r - q;

    for(int i = 0; i< n; i++){
        L.push_back(v[p+i -1]);
    }
    for(int j = 0; j< m; j++){
        R.push_back(v[q + j]);
    }
    L.push_back(pair<int,string> (0,"TEST"));
    R.push_back(pair<int,string> (0,"TEST"));
    /*
    cout<<"L vector:"<<endl;
    for (int i=0; i<R.size(); i++){
        cout << L[i].first << ' ' << L[i].second << endl;
    }
    cout<<"R vector:"<<endl;
    for (int i=0; i<L.size(); i++){
        cout << R[i].first << ' ' << R[i].second << endl;
    }
    */
      
    int i = 0;
    int j = 0;
    for(int k = 0; k< v.size(); k++){
        if(L[i].first >= R[j].first){
            v[k] = L[i];
            i++;
            //cout<<"1t"<<endl;
        }else{
            v[k] = R[j];
            j++;
            //cout<<"2t"<<endl;
        }
    }
    
}
void mergesort(vector<pair<int, string> >& v, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(v,p,q);
        mergesort(v,q+1,r);
        merge(v,p,q,r);
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
    

    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;



void merge(vector<pair<int,string> >& v, int p, int q, int r){
    int n = q - p + 1;
    int m = r - q;
    
    vector<pair<int, string> > L;
    vector<pair<int, string> > R;

    for(int i = 0; i< n; i++){
        L.push_back(v[p+i]);
    }
    for(int j = 0; j< m; j++){
        R.push_back(v[q + j+1]);
    }
    L.push_back(pair<int,string> (0,"TEST"));
    R.push_back(pair<int,string> (0,"TEST"));
    /*
    cout<<"L vector:"<<endl;
    for (int i=0; i<R.size(); i++){
        cout << L[i].first << ' ' << L[i].second << endl;
    }
    cout<<"R vector:"<<endl;
    for (int i=0; i<L.size(); i++){
        cout << R[i].first << ' ' << R[i].second << endl;
    }
    */
      
    int i = 0;
    int j = 0;
    /*
    for(int k = 0; k< v.size(); k++){
        if(L[i].first >= R[j].first){
            v[k] = L[i];
            i++;
            //cout<<"1t"<<endl;
        }else{
            v[k] = R[j];
            j++;
            //cout<<"2t"<<endl;
        }
    }
    */
    int k = p;
    while(i <n && j<m){
        if(L[i]>= R[j]){
            v[k]=L[i];
            i++;
        }else{
            v[k] = R[j];
            j++;
        }
        k++;
    }
    while(j<m){
        v[k] = R[j];
        j++;
        k++;
    }
    while(i<n){
        v[k] = L[i];
        i++;
        k++;
    }
    
}
void mergesort(vector<pair<int, string> >& v, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(v,p,q);
        mergesort(v,q+1,r);
        merge(v,p,q,r);
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
    

    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <climits>
using namespace std;



void merge(vector<pair<int,string> >& v, int p, int q, int r){
    int n = q - p + 1;
    int m = r - q;
    
    vector<pair<int, string> > L;
    vector<pair<int, string> > R;

    for(int i = 0; i< n; i++){
        L.push_back(v[p+i]);
    }
    for(int j = 0; j< m; j++){
        R.push_back(v[q + j+1]);
    }
    L.push_back(pair<int,string> (0,"TEST"));
    R.push_back(pair<int,string> (0,"TEST"));
      
    int i = 0;
    int j = 0;
    int k = p;
    while(i <n && j<m){
        if(L[i].first >= R[j].first){
            v[k]=L[i];

            i++;
        }else{
            v[k] = R[j];

            j++;
        }
        k++;
    }
    while(j<m){
        v[k] = R[j];

        j++;
        k++;
    }
    while(i<n){
        v[k] = L[i];
        i++;
        k++;
    }
    
}
void mergesort(vector<pair<int, string> >& v, int p, int r){
    if(p<r){
        int q = (p+r)/2;
        mergesort(v,p,q);
        mergesort(v,q+1,r);
        merge(v,p,q,r);
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
    

    // merge sort
    mergesort(v, 0, v.size()-1);

    for (int i=0; i<n; i++){
        cout << v[i].first << ' ' << v[i].second << endl;
    }

    return 0;
}