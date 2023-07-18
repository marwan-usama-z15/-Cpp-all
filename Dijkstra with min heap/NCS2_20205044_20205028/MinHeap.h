#ifndef MINHEAP_H
#define MINHEAP_H
using namespace std;

struct Node{
    char label;
    int cost;
};

class MinHeap{
    Node* heap;
    int _size;

public:
    Node extractMin(){

        Node minn;

        if(_size<0){
            cout<<"heap under flow"<<endl;
        }

        minn=heap[0];
        heap[0]=heap[_size-1];
        _size--;
        minHeapify(0,_size);
        return minn;
    }

    void swap(Node *a, Node *b){
        Node temp = *b;
        *b = *a;
        *a = temp;
    }

    void buildMinHeap( Node n[],int x){
        _size=x;
        heap=n;

        for (int i=(_size/2)-1; i>=0; i--){
            minHeapify(i,_size);
        }
    }

    void minHeapify(int i, int n){
        int l =(2*i) +1 ;
        int r =(2*i) + 2 ;
        int smallest = i;

        if (l <n && heap[l].cost <heap[i].cost){
            smallest = l;
        }

        if (r < n&&heap[r].cost< heap[smallest].cost ){
            smallest = r;
        }

        if (smallest != i){
            swap(&heap[i],&heap[smallest]);
            minHeapify (smallest,n);
        }
    }

    void decreaseKey(char label,int newCost){

        int j=0;
        for(int i=0 ; i<_size; i++){
            if (heap[i].label==label){
                heap[i].cost=newCost;
                j=i;
                break;
            }
        }

        while(j>0&&heap[parent(j)].cost<heap[j].cost){
            swap(&heap[j],&heap[parent(j)]);
            j=parent(j);
        }

    }

    int parent(int i){
        return ((i-1)/2) ;
    }

    int getSize(){
        return _size;
    }

    bool inHeap(char l){
        for(int i=0; i<_size; i++){
            if (heap[i].label==l)
                return true;
        }

        return false;
        }
};


#endif
