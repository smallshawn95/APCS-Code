#include <iostream>
#include <vector>
using namespace std;

int num[51][51];
vector<pair<int, int>> ans;

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> num[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int x = num[i][j];
            int x_start = j - x, x_end = j + x;
            int y_start = i - x, y_end = i + x;
            if(x_start < 0){
                x_start = 0;
            }
            if(x_end >= m){
                x_end = m - 1;
            }
            if(y_start < 0){
                y_start = 0;
            }
            if(y_end >= n){
                y_end = n - 1;
            }
            int total = 0;
            for(int k = y_start; k <= y_end; k++){
                for(int l = x_start; l <= x_end; l++){
                    if(abs(k - i) + abs(l - j) <= num[i][j]){
                        total += num[k][l];
                    }
                }
            }
            if(total % 10 == x){
                ans.push_back({i, j});
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto i: ans){
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}
