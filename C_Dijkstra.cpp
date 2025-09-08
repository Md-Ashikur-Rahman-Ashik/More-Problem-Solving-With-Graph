#include <bits/stdc++.h>
using namespace std;

vector<pair<long long int, long long int>> adjacencyList[100005];
long long int distanceArray[100005];
long long int parentArray[100005];

void dijkstra(int sourceNode)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pairQueue;
    pairQueue.push({0, sourceNode});
    distanceArray[sourceNode] = 0;

    while (!pairQueue.empty())
    {
        pair<long long int, long long int> parentPair = pairQueue.top();
        pairQueue.pop();

        long long int parentNode = parentPair.second;
        long long int distanceOfParent = parentPair.first;

        for (auto childPair : adjacencyList[parentNode])
        {
            long long int childNode = childPair.first;
            long long int distanceOfChild = childPair.second;

            if (distanceOfParent + distanceOfChild < distanceArray[childNode])
            {
                distanceArray[childNode] = distanceOfParent + distanceOfChild;
                pairQueue.push({distanceArray[childNode], childNode});

                parentArray[childNode] = parentNode;
            }
        }
    }
}

int main()
{
    long long int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;

    for (int i = 1; i <= numberOfEdge; i++)
    {
        long long int firstNode, secondNode, weight;
        cin >> firstNode >> secondNode >> weight;

        adjacencyList[firstNode].push_back({secondNode, weight});
        adjacencyList[secondNode].push_back({firstNode, weight});
    }

    for (int i = 1; i <= numberOfNode; i++)
    {
        parentArray[i] = -1;
        distanceArray[i] = LLONG_MAX;
    }

    dijkstra(1);

    if (distanceArray[numberOfNode] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        long long int destinationNode = numberOfNode;
        vector<long long int> shortestPath;

        while (destinationNode != -1)
        {
            shortestPath.push_back(destinationNode);
            destinationNode = parentArray[destinationNode];
        }

        reverse(shortestPath.begin(), shortestPath.end());

        for (auto individualNode : shortestPath)
        {
            cout << individualNode << " ";
        }
    }

    return 0;
}