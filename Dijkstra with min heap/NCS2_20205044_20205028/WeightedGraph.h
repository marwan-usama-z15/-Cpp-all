#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
using namespace std;


class WeightedGraph{
    int** g;
    int nVertices;

public:
    int z;

    int toInt(char character)
{
    int A=character-97;
    return A;
}

    int getNVertices(){

        return nVertices;
    }

    int getWeight(char f,char p){
        return g[toInt(f)][toInt(p)];
    }

    int* returnNeighbors(int v){
        int siz;
        siz=numNeighbors(v);
        int *adjc=new int[siz];
        int x=0;
        int i=0;

        while (i<nVertices){
            if (g[v][i]>0){
                adjc[x]=i;
                x++;
            }
            i++;
        }
        return adjc;
    }

    int numNeighbors(int v){
        int  c=0;
        for(int i=0; i<nVertices; i++){
            if (g[v][i]>0)
                c++;
        }
        return c;
    }

    void loadGraphFromFile(ifstream& x){
        int n, m;
        x >> n >> m ;
        nVertices=n;
        z=m;
        g = new int*[n];
        for(int i = 0; i <  n; i++){
            g[i] = new int[n];
            for(int j = 0; j < n; j++)g[i][j] = 0;
        }

        char h,y;
        int d;
        for(int i = 0; i < m; i++){
            x >>h>>y ;
            x>>d;
            g[h-97][y-97] = d ;
        }
    }

    void dijkstra(char startVertex, char* prev, Node distances[] ){
        MinHeap obj;
        Node extract;
        Node copiedNode[nVertices];
        int calc=toInt(startVertex);
        char u;
        for (int i=0; i<nVertices; i++){
            u=i+97;
            distances[i].cost=INT_MAX;
            distances[i].label=u;
        }
        distances[calc].cost=0;
        distances[calc].label=startVertex;
        prev[calc]=startVertex;
        for(int i=0; i<nVertices; i++){
            copiedNode[i]=distances[i];
        }
        int *nub=returnNeighbors(calc);
        for (int i=0; i<numNeighbors(calc); i++){
            distances[nub[i]].cost=g[calc][nub[i]];
            prev[nub[i]]=startVertex;
            copiedNode[nub[i]].cost=g[calc][nub[i]];
        }
        obj.buildMinHeap(copiedNode,nVertices);
        obj.extractMin();

        for (int i=0; i<nVertices; i++){

            extract=obj.extractMin();
            nub=returnNeighbors(toInt(extract.label));

                for (int j=0; j<numNeighbors(toInt(extract.label)); j++){

                   if((distances[toInt(extract.label)].cost)+(g[toInt(extract.label)][nub[j]])<distances[nub[j]].cost){
                        distances[nub[j]].cost=distances[toInt(extract.label)].cost+g[toInt(extract.label)][nub[j]];
                        prev[nub[j]]=extract.label;
                        obj.decreaseKey(distances[nub[j]].label,distances[toInt(extract.label)].cost+g[toInt(extract.label)][nub[j]]);
                    }
                }
        }
    }
};



#endif
