#include <iostream>
using namespace std;
int Hswap;
int Lswap;
int Hcom;
int Lcom;

inline void swap(int & a, int & b){
	int t = a;
    a = b; 
    b = t;
}

int partition_Hoare(int A[],int low,int high){
    int pivot = A[low];
    int i = low - 1;
    int j = high + 1;
    while(true){
        do{
            i = i+1;
            Hcom++; 
            }while ( A[i] < pivot ); // 비교(comparison) 연산자 ‘<’
        do{
            j = j-1; 
            Hcom++;
            }while (A[j] > pivot); // 비교(comparison) 연산자 ‘<’
        if(i < j){
            swap(A[i], A[j]);
            Hswap++;
            }// swap 연산
        else{
            return j;
        }
    }
}

int H_quicksort(int A[],int low,int high){
    if(low >= high){
        return -1;
    }
    int qp = partition_Hoare(A, low, high);
    H_quicksort(A, low, qp);
    H_quicksort(A, qp+1, high);
}


 ///////////////////

 int partition_Lomuto(int A[],int low,int high){
    int pivot, j;
    pivot = A[low];
    j = low;
    for(int i = low+1; i <= high; i++){
        Lcom++;
        if(A[i] < pivot ){
            j = j + 1;
            swap(A[i], A[j]);
            Lswap++;
        }
    }// swap 연산
    int pivot_pos = j;
    swap(A[pivot_pos],A[low]);
    Lswap++; // swap 연산
    return pivot_pos;
}
 int L_quicksort(int A[],int low,int high){
    if(low >= high ){
        return -1;
    }
    int p = partition_Lomuto(A, low, high);
    L_quicksort(A, low, p-1);
    L_quicksort(A, p+1, high);
 }




 int main(){
    int numTestCases;
    cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
      int arraysize;
      cin >> arraysize;

      int A[arraysize], B[arraysize];
      for( int i = 0; i < arraysize; i++){
          int num;
          cin>> num;
          A[i] = num;
          B[i] = num;
      }
      Hswap = 0;
      Lswap = 0;
      Hcom = 0;
      Lcom = 0;

      H_quicksort(A,0,arraysize-1);
      L_quicksort(B,0,arraysize-1);

    cout << Hswap <<" "<<Lswap <<" "<< Hcom<<" "<< Lcom <<endl;
    // cout << endl<<"B:";
    // for(int i = 0; i< arraysize; i++){
    //     cout<< B[i]<< " ";
    // }

      


  }
    

    return 0;
}