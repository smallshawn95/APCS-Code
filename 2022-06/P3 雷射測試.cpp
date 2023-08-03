#include <iostream>
#include <algorithm>
using namespace std;

struct Data{
    int x, y, idx;
}point[250001];

int t[250001], adj[250001][4];
int east = 0, south = 1, west = 2, north = 3;
int next_d[2][4] = {{north, west, south, east}, {south, east, north, west}};

bool cmpX(Data a, Data b)
{
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmpY(Data a, Data b)
{
    if(a.y == b.y){
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, y;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> t[i];
        point[i] = {x, y, i};
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            adj[i][j] = -1;
        }
    }
    sort(point, point + n, cmpX);
    for(int i = 0; i < n - 1; i++){
        if(point[i].x == point[i + 1].x){
            adj[point[i].idx][north] = point[i + 1].idx;
            adj[point[i + 1].idx][south] = point[i].idx;
        }
    }
    int v = -1;
    sort(point, point + n, cmpY);
    for(int i = 0; i < n - 1; i++){
        if(point[i].y == point[i + 1].y){
            adj[point[i].idx][east] = point[i + 1].idx;
            adj[point[i + 1].idx][west] = point[i].idx;
        }
        if(v == -1 && point[i].y == 0){
            v = point[i].idx;
        }
    }
    int d = east, hit = 0;
    while(v >= 0){
        hit += 1;
        d = next_d[t[v]][d];
        v = adj[v][d];
    }
    cout << hit << '\n';
    return 0;
}
