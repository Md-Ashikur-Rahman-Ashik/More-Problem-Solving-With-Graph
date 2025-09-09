#include <bits/stdc++.h>
using namespace std;

int rowAndColumn;
char grid[35][35];
int visitedArray[35][35];
int levelArray[35][35];
vector<pair<int, int>> pairVector = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool valid(int rowOfChild, int columnOfChild)
{
    if (rowOfChild < 0 || rowOfChild >= rowAndColumn || columnOfChild < 0 || columnOfChild >= rowAndColumn)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void bfs(int rowOfSource, int columnOfSource)
{
    queue<pair<int, int>> pairQueue;
    pairQueue.push({rowOfSource, columnOfSource});
    visitedArray[rowOfSource][columnOfSource] = true;
    levelArray[rowOfSource][columnOfSource] = 0;

    while (!pairQueue.empty())
    {
        pair<int, int> parentPair = pairQueue.front();
        pairQueue.pop();

        int rowOfParent = parentPair.first;
        int columnOfParent = parentPair.second;

        for (int i = 0; i < 4; i++)
        {
            int rowOfChild = rowOfParent + pairVector[i].first;
            int columnOfChild = columnOfParent + pairVector[i].second;

            if (valid(rowOfChild, columnOfChild) == true && visitedArray[rowOfChild][columnOfChild] == false && (grid[rowOfChild][columnOfChild] == 'P' || grid[rowOfChild][columnOfChild] == 'E'))
            {
                pairQueue.push({rowOfChild, columnOfChild});
                visitedArray[rowOfChild][columnOfChild] = true;
                levelArray[rowOfChild][columnOfChild] = levelArray[rowOfParent][columnOfParent] + 1;
            }
        }
    }
}

int main()
{
    cin >> rowAndColumn;

    int rowOfSource, columnOfSource, rowOfDestination, columnOfDestination;

    for (int i = 0; i < rowAndColumn; i++)
    {
        for (int j = 0; j < rowAndColumn; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                rowOfSource = i;
                columnOfSource = j;
            }
            else if (grid[i][j] == 'E')
            {
                rowOfDestination = i;
                columnOfDestination = j;
            }
        }
    }

    memset(visitedArray, false, sizeof(visitedArray));
    memset(levelArray, -1, sizeof(levelArray));

    bfs(rowOfSource, columnOfSource);
    cout << levelArray[rowOfDestination][columnOfDestination] << endl;

    return 0;
}