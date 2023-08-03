#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> me(n, 0), classmate(n);
    for(int i = 0; i < n; i++){
        cin >> classmate[i];
    }
    int idx, ans = 0;
    for(int i = 0; i < n; i++){
        bool no = true;
        idx = i;
        while(!me[idx]){
            me[idx] = 1;
            idx = classmate[idx];
            no = false;
        }
        if(!no){
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
