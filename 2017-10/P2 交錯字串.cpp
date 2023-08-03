#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, flag, len, key, ans = 0;
    string str;
    vector<string> v;
    cin >> k;
    cin >> str;
    len = str.length();
    v.push_back(string(k, 'a'));
    v.push_back(string(k, 'A'));
    for(int i = 0; i < len; i++){
        if(islower(str[i])){
            str[i] = 'a';
        }else{
            str[i] = 'A';
        }
    }
    for(int i = 0; i < len; i++){
        if(islower(str[i])){
            flag = 0;
        }else{
            flag = 1;
        }
        key = 0;
        for(int j = i; j + k <= len; j += k){
            if(str.substr(j, k) == v[flag]){
                key += k;
                flag = (flag + 1) % 2;
            }else{
                break;
            }
            ans = max(ans, key);
        }
    }
    cout << ans << '\n';
    return 0;
}
