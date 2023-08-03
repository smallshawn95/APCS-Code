#include <iostream>
#include <vector>
using namespace std;

int f[1001];
long long s[1001], t[1001];

int main()
{
    int n, m, i, j, wi, lo;
    long long s0, t0;
    vector<int> idx;
    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> s[i];
    }
    for(i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(i = 1; i <= n; i++){
        cin >> j;
        idx.push_back(j);
    }
    while(idx.size() > 1){
        vector<int> win, lose;
        for(i = 0; i < idx.size() - 1; i += 2){
            j = i + 1;
            if(s[idx[i]] * t[idx[i]] >= s[idx[j]] * t[idx[j]]){
                wi = idx[i];
                lo = idx[j];
            }else{
                wi = idx[j];
                lo = idx[i];
            }
            win.push_back(wi);
            if(++f[lo] != m){
                lose.push_back(lo);
            }
            s0 = s[wi] + s[lo] * t[lo] / (2 * t[wi]);
            t0 = t[wi] + s[lo] * t[lo] / (2 * s[wi]);
            s[wi] = s0;
            t[wi] = t0;
            if(!lose.empty() && lo == lose.back()){
                s[lo] += s[lo] / 2;
                t[lo] += t[lo] / 2;
            }
        }
        if(i + 1 == idx.size()){
            win.push_back(idx[i]);
        }
        idx.clear();
        idx.insert(idx.end(), win.begin(), win.end());
        idx.insert(idx.end(), lose.begin(), lose.end());
    }
    cout << idx[0] << '\n';
    return 0;
}
