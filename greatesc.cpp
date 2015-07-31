#include<iostream>
using namespace std;
long n,m;
int length[3501] = {0};
int dist[3501];
int list[3501][3501];
bool visited[3501] = {0};
int a,b,s,t;
 
int min(int a,int b)
{
        if(a>b)
                return b;
        return a;
}
 
void findpath(int currentpos)
{
        if(visited[currentpos])
                return;
        visited[currentpos] = 1;
        for(int i = 0; i < length[currentpos]; ++i)
        {
                dist[list[currentpos][i]] = min(dist[currentpos]+1,dist[list[currentpos][i]]);
        }
        int mindist = 10001;
        int minpos;
        for(int i = 1; i <= n; ++i)
        {
                if(!visited[i])
                        if(mindist > dist[i])
                                {
                                        mindist = dist[i];
                                        minpos = i;
                                }
        }
        findpath(minpos);
}
 
int main(void)
{
        cin >> n >> m;
        for(int i = 0; i <= n; ++i)
                dist[i] = 10000;
        for(int i = 0; i < m; ++i)
        {
                cin >> a >> b;
                list[a][length[a]] = b;
                list[b][length[b]] = a;
                ++length[a];
                ++length[b];
        }
        cin >> s >> t;
        dist[s] = 0;
        findpath(s);
        if(dist[t] == 10000)
                cout << 0;
        else
                cout << dist[t];
        return 0;
}
