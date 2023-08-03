#include <iostream>
using namespace std;

int n, k, h[200001], w[50001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int left = 1, right = 0;
    for(int i = 1; i <= n; i++){
        cin >> h[i];
        right = max(right, h[i]);
    }
    right += 1;
    for(int i = 1; i <= k; i++){
        cin >> w[i];
    }
    while(right - 1 > left){
        int mid = (left + right) / 2;
        int cnt = 0, now = 1;
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(h[i] >= mid){
                cnt += 1;
                if(cnt >= w[now]){
                    cnt -= w[now];
                    if(now == k){
                        flag = true;
                        break;
                    }
                    now += 1;
                }
            }else{
                cnt = 0;
            }
        }
        if(flag){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left << '\n';
    return 0;
}
