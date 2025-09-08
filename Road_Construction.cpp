#include <bits/stdc++.h>
using namespace std;

int parentArray[100005];
int sizeArray[100005];
int countComponent, maxSize;

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
        maxSize = max(maxSize, sizeArray[firstLeader]);
    }
    else
    {
        parentArray[firstLeader] = secondLeader;
        sizeArray[secondLeader] = sizeArray[secondLeader] + sizeArray[firstLeader];
        maxSize = max(maxSize, sizeArray[secondLeader]);
    }

    countComponent--;
}

int main()
{
    int numberOfNode, numberOfEdge;
    cin >> numberOfNode >> numberOfEdge;

    countComponent = numberOfNode;
    maxSize = 1;

    for (int i = 1; i <= numberOfNode; i++)
    {
        parentArray[i] = -1;
        sizeArray[i] = 1;
    }

    for (int i = 1; i <= numberOfEdge; i++)
    {
        int firstNode, secondNode;
        cin >> firstNode >> secondNode;
        dsuUnion(firstNode, secondNode);

        cout << countComponent << " " << maxSize << endl;
    }

    return 0;
}