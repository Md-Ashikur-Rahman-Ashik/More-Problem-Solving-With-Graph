#include <bits/stdc++.h>
using namespace std;

int parentArray[1005];
int sizeArray[1005];

int find(int node)
{
    if (parentArray[node] == -1)
    {
        return node;
    }
    else
    {
        int leader = find(parentArray[node]);
        parentArray[node] = leader;
        return leader;
    }
}

void dsuUnion(int firstNode, int secondNode)
{
    int firstLeader = find(firstNode);
    int secondLeader = find(secondNode);

    if (firstLeader == secondLeader)
    {
        return;
    }

    if (sizeArray[firstLeader] > sizeArray[secondLeader])
    {
        parentArray[secondLeader] = firstLeader;
        sizeArray[firstLeader] = sizeArray[firstLeader] + sizeArray[secondLeader];
    }
    else
    {
        parentArray[firstLeader] = secondLeader;
        sizeArray[secondLeader] = sizeArray[secondLeader] + sizeArray[firstLeader];
    }
}

int main()
{
    int numberOfNode;
    cin >> numberOfNode;

    for (int i = 1; i <= numberOfNode; i++)
    {
        parentArray[i] = -1;
        sizeArray[i] = 1;
    }

    vector<pair<int, int>> removableEdge;
    vector<pair<int, int>> createdEdge;

    for (int i = 0; i < numberOfNode - 1; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;

        int firstLeader = find(firstNode);
        int secondLeader = find(secondNode);

        if (firstLeader == secondLeader)
        {
            removableEdge.push_back({firstNode, secondNode});
        }
        else
        {
            dsuUnion(firstNode, secondNode);
        }
    }

    for (int i = 2; i <= numberOfNode; i++)
    {
        int firstLeader = find(1);
        int secondLeader = find(i);

        if (firstLeader != secondLeader)
        {
            createdEdge.push_back({1, i});
            dsuUnion(1, i);
        }
    }

    int removedEdgeSize = removableEdge.size();
    cout << removedEdgeSize << endl;

    for (int i = 0; i < removedEdgeSize; i++)
    {
        cout << removableEdge[i].first << " " << removableEdge[i].second << " " << createdEdge[i].first << " " << createdEdge[i].second << endl;
    }

    return 0;
}