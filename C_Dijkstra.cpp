#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjacencyList[100005];
int distanceArray[100005];

void dijkstra(int sourceNode){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pairQueue;
    pairQueue.push({0, sourceNode});
    distanceArray[sourceNode] = 0;

    while (!pairQueue.empty())
    {
        pair<int, int> parentPair = pairQueue.top();
        pairQueue.pop();
    }
    
}

int main()
{
    return 0;
}