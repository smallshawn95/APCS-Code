#include <iostream>
#include <vector>
using namespace std;

int ans[100005];
vector<int> tree[100005];

void dfs(int now, int pre)
{
    for(auto& i: tree[now]){
        if(i != pre){
            ans[i] = ans[now] + 1;
            dfs(i, now);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            ans[i] = 0;
            tree[i].clear();
        }
        for(int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
        }
        dfs(0, -1);
        int idx = 0, max_ans = 0;
        for(int i = 0; i < n; i++){
            if(ans[i] > max_ans){
                max_ans = ans[i];
                idx = i;
            }
        }
        for(int i = 0; i < n; i++){
            ans[i] = 0;
        }
        dfs(idx, -1);
        for(int i = 0; i < n; i++){
            if(ans[i] > max_ans){
                max_ans = ans[i];
            }
        }
        cout << max_ans << '\n';
    }
    return 0;
}
