#include <iostream>
#include <stack>
using namespace std;

int c[100002], h[100002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l;
    stack<int> s;
    int total = 0, height = 0;
    cin >> n >> l;
    c[0] = 0;
    h[0] = 2147483647;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> h[i];
    }
    c[n + 1] = l;
    s.push(0);
    for(int i = 1; i <= n; i++){
        if(c[i] - h[i] >= c[s.top()] || c[i] + h[i] <= c[i + 1]){
            total += 1;
            height = max(height, h[i]);
            while(c[s.top()] + h[s.top()] <= c[i + 1]){
                total += 1;
                height = max(height, h[s.top()]);
                s.pop();
            }
        }else{
            s.push(i);
        }
    }
    cout << total << '\n' << height << '\n';
    return 0;
}
