#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    pair<long long, long long> point[n];
    for(int i = 0; i < n; i++){
        cin >> point[i].first >> point[i].second;
    }
    sort(point, point + n);
    int ans = 0, start, end;
    for(int i = 0; i < n; i++){
        start = point[i].first;
        end = point[i].second;
        while(i + 1 < n && point[i + 1].first < end){
            if(point[i + 1].second < end){
                i += 1;
            }else{
                end = point[i + 1].second;
                i += 1;
            }
        }
        ans += end - start;
    }
    cout << ans << '\n';
    return 0;
}
