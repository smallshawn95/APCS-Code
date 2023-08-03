#include <iostream>
#include <algorithm>
using namespace std;

pair<long long, long long> num[100001];

bool cmp(pair<long long, long long> a, pair<long long, long long> b)
{
    return a.first * b.second < b.first * a.second;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> num[i].second;
    }
    sort(num, num + n, cmp);
    long long ans = 0, temp = 0;
    for(int i = 0; i < n - 1; i++){
        temp += num[i].first;
        ans += temp * num[i + 1].second;
    }
    cout << ans << '\n';
    return 0;
}
