#include <iostream>
using namespace std;

int main()
{
    bool no = 1;
    int x, y, ans = 0;
    cin >> x >> y;
    int num[x][y], max[x];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            cin >> num[i][j];
        }
    }
    for(int i = 0; i < x; i++){
        max[i] = 0;
        for(int j = 0; j < y; j++){
            if(num[i][j] > max[i]){
                max[i] = num[i][j];
            }
        }
        ans += max[i];
    }
    cout << ans << '\n';
    for(int i = 0; i < x; i++){
        if(ans % max[i] == 0 && no == 0){
            cout << ' ' << max[i];
        }else if(ans % max[i] == 0){
            cout << max[i];
            no = 0;
        }
    }
    if(no){
        cout << -1 << '\n';
    }
    return 0;
}
