#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, ans = 0;
    string str;
    vector<string> v;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end());
    for(auto s : v){
        int len = s.length();
        for(int i = 1; i <= len / 2; i++){
            if(s.substr(0, i) == s.substr(len - i, i)){
                if(binary_search(v.begin(), v.end(), s.substr(i, len - 2 * i))){
                    ans += 1;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
