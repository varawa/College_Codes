#include <bits/stdc++.h>

using namespace std ;

const int INF = 1e9 ;

void dijkstra(int start , const vector<vector<pair<int , int>>>& adjList){
    int n = adjList.size()  ; 
    vector<int> dist(n , INF) ;
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq ;

    dist[start] = 0 ;
    pq.push({0 , start}) ;

    while(!pq.empty()){
        int u = pq.top().second ;
        int d = pq.top().first ;
        pq.pop() ;

        if (d > dist[u]) 
            continue ;

        for(const auto& edge : adjList[u]){
            int v = edge.first ;
            int weight = edge.second ;

            if(dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight ;
                pq.push({dist[v] , v}) ;
            }
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(dist[i] == INF){
            cout<<"Minimum distance from node "<<start<<" to node "<<i<<" is INF"<<endl ;
        }else{
            cout<<"Minimum distance from node "<<start<<" to node "<<i<<" is "<<dist[i]<<endl ;
        }
    }
}

int main() {
    // Number of nodes and edges
    int n , m ; 
    cout<<"Enter number of nodes and edges: " ;
    cin>> n >> m ;

    vector<vector<pair<int , int>>>adjList(n) ;

    cout << "Enter edges (u v w):"<<endl ;
    for(int i = 0 ; i < m ; i++){
        int u , v , w ;
        cin>>u>>v>>w ;
        adjList[u].push_back({v, w}) ;
        adjList[v].push_back({u, w}) ;
    }

    int startNode ;
    cout<<"Enter starting node: " ;
    cin>>startNode ;

    dijkstra(startNode , adjList) ;

    return 0 ;
}
