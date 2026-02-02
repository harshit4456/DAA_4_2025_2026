//4.1 DELETE AND INSERT IN MIN HEAP
#include<bits/stdc++.h>

using namespace std;

#define MAX 1000
int heapSize=0;

int heap[MAX];

void heapifyUp(int i) {

while(i>0 && heap[(i-1)/2]> heap[i]) {

swap(heap[i] , heap[(i-1)/2]);
i = (i-1)/2;
}
}

void insert(int val) {

if(heapSize==MAX) {
cout<<"heap full";
return;
}
heap[heapSize] = val;
heapSize++;
heapifyUp(heapSize-1);

}

void heapifyDown(int i ) {

int smallest = i;
int left = 2*i+1;
int right = 2*i+2;

if(left<heapSize && heap[smallest] > heap[left] ) smallest = left;
if(right<heapSize && heap[smallest] > heap[right]) smallest = right;
  
if(smallest!=i) {
swap(heap[smallest] , heap[i]);
heapifyDown(smallest);
}
}
void deleteMin() {

if(heapSize==0) {
cout<<"empty"<<endl;
return;
}
heap[0] =heap[heapSize-1];
heapSize--;
heapifyDown(0);
} 
int main() {
insert(10);
insert(20);
insert(1);
insert(0);

for(int i =0;i<heapSize;i++) cout<<heap[i]<< " ";

  //4.2 DELETE ANY NODE IN MIN-HEAP
  #include<bits/stdc++.h>
using namespace std;
int heap[1000];
int heapSize;
void heapifyDown(int i){
    while(true){
        int l=2*i+1,r=2*i+2,s=i;
        if(l<heapSize&&heap[l]<heap[s])s=l;
        if(r<heapSize&&heap[r]<heap[s])s=r;
        if(s==i)break;
        swap(heap[i],heap[s]);
        i=s;
    }
}
void heapifyUp(int i){
    while(i>0&&heap[(i-1)/2]>heap[i]){
        swap(heap[i],heap[(i-1)/2]);
        i=(i-1)/2;
    }
}
void deleteAtIndex(int index){
    if(index<0||index>=heapSize)return;
    heap[index]=heap[heapSize-1];
    heapSize--;
    heapifyDown(index);
    heapifyUp(index);
}
int main(){
    heap[0]=2;
    heap[1]=5;
    heap[2]=10;
    heap[3]=7;
    heap[4]=15;
    heapSize=5;
    deleteAtIndex(1);
    for(int i=0;i<heapSize;i++)cout<<heap[i]<<" ";
    return 0;
}


}	
