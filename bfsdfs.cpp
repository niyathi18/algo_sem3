#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;
template <typename T>

class Graph{
public :
    unordered_map<T, list<T > > adjList;

    void addEdge(T u,T v,bool direction){
        //direction =0 -> undirected graph
        //direction =1 ->directed graph

        //creating an edge from u to v
        adjList[u].push_back(v);
        if(direction==0){
            //undirected edge
            //creating an edge from v to u
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<<node.first<< " -> ";
            for(auto neighbour : node.second){
                cout<<neighbour <<" , ";
            }
            cout<<endl;
        }
    }

    void bfs(int src, unordered_map<int,bool> &visited){
        queue<int> q;
       
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            cout<< frontNode <<" ,";

            //inserting neighbours
            for(auto neighbour: adjList[frontNode]){
                if(!visited[neighbour]==true){
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
        }
    }

    void dfs(int src, unordered_map<int,bool> &visited2){
        cout<<src<<" ,";
        visited2[src]=true;
        for(auto neighbour: adjList[src]){
            if(!visited2[neighbour]==true){
                dfs(neighbour,visited2);
            }
        }
    }
};


// class Graph{
// public :
//     unordered_map<int, list<pair<int,int> > > adjList;

//     void addEdge(int u,int v,int weight, bool direction){
//         //direction =0 -> undirected graph
//         //direction =1 ->directed graph

//         //creating an edge from u to v
//         adjList[u].push_back({v,weight});
//         if(direction==0){
//             //undirected edge
//             //creating an edge from v to u
//             adjList[v].push_back({u,weight});
//         }
//     }

//     void printAdjList(){
//         for(auto node: adjList){
//             cout<<node.first<< " -> ";
//             for(auto neighbour : node.second){
//                 cout<<"("<<neighbour.first<<","<<neighbour.second<<")" <<" , ";
//             }
//             cout<<endl;
//         }
//     }
// };

int main(){

   Graph<int> g;
   g.addEdge(0,1,0);
   g.addEdge(1,2,0);
   g.addEdge(1,3,0);
   g.addEdge(3,5,0);
   g.addEdge(3,7,0);
   g.addEdge(7,6,0);
   g.addEdge(7,4,0);
   g.printAdjList();
   cout<<endl;
   unordered_map<int,bool> visited;
   //running a loop for all nodes
   cout<<"printing BFS"<<endl;
   for(int i=0;i<=7;i++){
    if(!visited[i]){
        g.bfs(i,visited);
    }
   }cout<<endl;
   unordered_map<int,bool> visited2;
   cout<<"printing DFS"<<endl;
   for(int i=0;i<=7;i++){
    if(!visited2[i]){
        g.dfs(i,visited2);
    }
   }
   
//    g.addEdge('a','b',0);
//    g.addEdge('b','c',0);
//    g.addEdge('a','c',0);
//    g.printAdjList();


//    //undirected edge input --> similarly you can try for directed input.
//    g.addEdge(0,1,1,0);
//    g.addEdge(1,2,8,0);
//    g.addEdge(0,2,6,0);
//    g.printAdjList();
    

    // int n;
    // cout<<"Enter no.of nodes : "<<endl;
    // cin>>n;
    
    // //creating a 2D adj matrix, with name adj, where (n->is no.of rows)
    // //and (n,vector<int>(n,0)) will be each row having a array of length n
    // //and initialized it with 0--->finally making it a n*n matrix
    // vector<vector<int> > adj(n,vector<int>(n,0));//ADJ MATRIX

    // int e;
    // cout<<"enter no.of edges : "<<endl;
    // cin>>e;

    // for(int i=0;i<e;i++){
    //     int u,v;
    //     cin>>u>>v;
    //     //minitialising all edges with 1
    //     adj[u][v]=1;
    // }

    // //printing

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<adj[i][j]<<" ";
    //     }cout<<endl;
    // }

    return 0;
}