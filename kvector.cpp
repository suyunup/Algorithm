/******************************************
    K-vector
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                20191687 한수연
**********************************************/
#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class Kvector{
protected:
  int *m;
  int len;
public:
  Kvector(int sz = 0,int value = 0);
  Kvector(const Kvector& v);
  Kvector& operator=(const Kvector& v);
friend bool operator==(const Kvector& v, const Kvector& w);
friend bool operator!=(const Kvector& v, const Kvector& w);
int& operator[] (int idx){return m[idx];}
const int& operator[] (int idx) const {return m[idx];}
friend ostream& operator<<(ostream& os, const Kvector& v);
  ~Kvector(){
    cout << this << ": ~Kvector() \n";
    delete[] m;
  }
  void print() const{
    for(int i = 0; i < len; i++){
      cout << m[i] << " ";
    }
    cout <<endl;
  }
  void clear(){
    delete[] m;
    m = NULL;
    len = 0;
  }
  int size(){
    return len;
  }
};
Kvector& Kvector::operator=(const Kvector& v){
    delete[] m;
    len = v.len;
    m = new int[len];
    for(int i = 0; i < len; i++){
      m[i] = v.m[i];
    }
  return *this;
}
ostream& operator<<(ostream& os, const Kvector& v){
  for(int i = 0; i < v.len; i++){
    os << v.m[i] << " ";
  }
  return os;
}
bool operator==(const Kvector& v, const Kvector& w){
  if(v.len != w.len){
    return false;
  }else{
    for(int i = 0; i < v.len; i++){
      if(v.m[i] != w.m[i]){
        return false;
      }
    }
  }
  return true;
}

bool operator!=(const Kvector& v, const Kvector& w){
  return !(v==w);
}


Kvector::Kvector(int sz,int value){
  cout << this << ": Kvector("<<sz<<","<< value<<")\n";
  if(!sz){
    m = NULL;
    return;
  }
    len = sz;
    m = new int[sz];
    for(int i = 0; i < len; i++){
      m[i] = value;
    }
}
Kvector::Kvector(const Kvector& v){
  cout << this << ": Kvector(* "<< &v<<")\n";
  len = v.len;
  if(!len){
    m = NULL;
    return;
  }
  m = new int[len];
  for(int i = 0; i < len; i++){
    m[i] = v.m[i];
  }
}
#define N 3
class Avector: public Kvector{
  char table[N];
public:
  Avector(int sz = 0, int v = 0, const char *t = "abc"):Kvector(sz, v){
    cout << this << ": Avector("<< sz<<","<<v<<","<<t<<")\n";
    setTable(t);
  }
  void setTable(const char *t){
    for(int i = 0; i < N; i++){
      table[i] = t[i];
    }
  }
friend ostream& operator<<(ostream& os, const Avector& v);
};
ostream& operator<<(ostream& os, const Avector& v){
  for(int i = 0; i < N; i++){
    os << v.table[v.m[i]%N] << " ";
  }
  return os;
}




int main(int argc, char *argv[]){
  if (argc != 2){
    cout <<"usage: ./avector pqr\n";
    return 1;
  }
  Avector v1(3); v1.print();
  Avector v2(2, 1, "xyz"); v2.print();
  Avector v3(v2); v3.print();
  cout << "v1 == v2 "<<(v1 == v2) << endl;
  cout << "v3 == v2 "<<(v3 == v2) << endl;
  v3 = v2 = v1;
  cout <<"v1 : " <<v1 << endl;
  v1.print();
  cout << "v2 : "<<v2 << endl;
  v2.print();
  cout << "v3 : "<<v3 << endl;
  v3.print();
  cout << "v3 != v2 "<<(v3 != v2) << endl;
  v1[2] = 2;
  v2[0] = v1[2];
  v1.setTable(argv[1]);
  cout << "v1: " << v1 << "v2: "<< v2 <<"v3: "<< v3 << endl;
  v1.print();
  v2.print();
  v3.print();
  return 0;

}
