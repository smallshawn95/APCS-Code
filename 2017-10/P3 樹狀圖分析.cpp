#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int h[100001], p[100001];
long long ans = 0;
vector<int> v[100001];

void dfs(int num)
{
    if(v[num].empty()){
        h[num] = 0;
    }else{
        int max_num = 0;
        for(auto& i: v[num]){
            dfs(i);
            max_num = max(max_num, h[i] + 1);
        }
        h[num] = max_num;
    }
}

int main()
{
    int n, num, temp, root;
    cin >> n;
    memset(p, -1, sizeof(p));
    for(int i = 0; i < n; i++){
        cin >> num;
        for(int j = 0; j < num; j++){
            cin >> temp;
            temp -= 1;
            v[i].push_back(temp);
            p[temp] = i;
        }
    }
    for(int i = 0; i < n; i++){
        if (p[i] == -1){
            root = i;
            break;
        }
    }
    dfs(root);
    ans = 0;
    for(int i = 0; i < n; i++){
        ans += h[i];
    }
    cout << root + 1 << '\n' << ans << '\n';
    return 0;
}
