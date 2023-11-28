#include<iostream>
#include<stack>
#include<unordered_map>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class graph{
public :
    unordered_map<int, list<int> > adjList;
    void addEdge(int u,int v,bool direction){
        adjList[u].push_back(v);
        if(direction==0){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto node: adjList){
            cout<<node.first<<"->";
            for(auto neighbour : node.second){
                cout<<neighbour<<" ,";
            }
            cout<<endl;
        }
    }

    void topoBfs(int n,vector<int> &ans){
        queue<int> q;
        unordered_map<int,int>  inDegree;
        //marking in degrees using adjList
        for(auto i: adjList){
            int src=i.first;
            for(auto nbr: i.second){
                inDegree[nbr]++;
            }
        }
        //put all nodes in queue which has in degree 0
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
            }   
        }
        //bfs logic
        while(!q.empty()){
            int fNode=q.front();
            q.pop();
            ans.push_back(fNode);
            for(auto nbr : adjList[fNode]){
                inDegree[nbr]--;
                //check if the inDegree is 0 or not
                if(inDegree[nbr]==0){
                    q.push(nbr);
                }
            }
        }

    }
};

int main(){
    graph g;
    int n = 8;
    g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(2,3,1);
	g.addEdge(3,4,1);

	g.addEdge(3,5,1);
	g.addEdge(4,6,1);
	g.addEdge(5,6,1);
	g.addEdge(6,7,1);
	//n -> number of nodes in graph
    vector<int> ans;
    //connected graph
   
     g.topoBfs(n,ans);
    
    for(auto i:ans){
        cout<<i<<" ,";
    }cout<<endl;



    return 0;
}