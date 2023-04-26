#include <iostream>
using namespace std;

int maxheapcounter;
int minheapcounter;


void minpop(int* heap){
    int temp = heap[1];
    heap[1] = heap[minheapcounter];
    heap[minheapcounter] = temp;
    minheapcounter--;

    int parent = 1;
    int child = parent*2;
    if(child +1 <= minheapcounter && heap[child] > heap[child+1]){
        child = child+1;
    }

    while(child<=minheapcounter && heap[parent] >heap[child]){
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;

        parent = child;
        child = child*2;
        if(child+1 <= minheapcounter && heap[child] > heap[child+1]){
            child = child+1;

        }
    }
}

void maxpop(int* heap){
    int temp = heap[1];
    heap[1] = heap[maxheapcounter];
    maxheapcounter--;

    int parent = 1;
    int child = parent*2;
    if(child +1 <= maxheapcounter && heap[child] < heap[child+1]){
        
        child = child+1;
        
    }

    while(child<=maxheapcounter && heap[parent] <heap[child]){
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;

        parent = child;
        child = child*2;
        if(child+1 <= maxheapcounter && heap[child] < heap[child+1]){
            child = child+1;
        }
    }
}




void maxheapAdd(int* maxheap,int data){
    maxheap[++maxheapcounter] = data;

    int child = maxheapcounter;
    int parent = child/2;
    int temp;
    while(child >1 && maxheap[parent] < maxheap[child]){
        
        temp = maxheap[parent];
        maxheap[parent] = maxheap[child];
        maxheap[child] = temp;

        child = parent;
        parent = child/2;
    }
}

void minheapAdd(int* minheap,int data){
    minheap[++minheapcounter] = data;

    int child = minheapcounter;
    int parent = child/2;
    int temp;
    while(child >1 && minheap[parent] > minheap[child]){
        temp = minheap[parent];
        minheap[parent] = minheap[child];
        minheap[child] = temp;

        child = parent;
        parent = child/2;
    }
}

int main(){
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++){
    int numData;
    int data;

    cin >> numData;
    int maxheap[numData+1] ={0,};
    int minheap[numData+1] = {0,};
    maxheapcounter = 0;
    minheapcounter = 0;
    unsigned long long int sum=0;
    for (int j = 0; j < numData; j++){
      cin >> data;

      if(j ==0){
          maxheapAdd(maxheap,data);
      }else if( data < maxheap[1]){
          maxheapAdd(maxheap,data);
      }else{
          minheapAdd(minheap,data);
      }


      if(maxheapcounter < minheapcounter){
          maxheapAdd(maxheap,minheap[1]);
          minpop(minheap);
      }else if(maxheapcounter > minheapcounter+1){
          minheapAdd(minheap, maxheap[1]);
          maxpop(maxheap);
      }

      if(maxheapcounter == minheapcounter){
          sum+=((maxheap[1]+minheap[1])/2)%10;
          cout<<"1"<<endl;
      }else{
          sum+= maxheap[1]%10;
          cout<<"2"<<endl;
      }


      ////////////////
    //   for(int k = 0; k<sizeof(maxheap)/sizeof(int); k++ ){
    //         cout<< maxheap[k]<<" ";
    //   }
    //   cout<< endl;
    //   for(int k = 0; k<sizeof(minheap)/sizeof(int); k++ ){
    //         cout<< minheap[k]<<" ";
    //   }
    //   cout<< endl;
      
      
    }
    cout <<sum%10<<endl;
  }
  return 0;

}