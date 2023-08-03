#include <iostream>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int a, b, wrong = 0, max_ans = -1, max_time = 0;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        if(b > max_ans){
            max_time = a;
            max_ans = b;
        }
        if(b == -1){
            wrong += 1;
        }
    }
    int ans = max_ans - k - 2 * wrong;
    if(ans <= 0){
        cout << 0 << ' ' << max_time << '\n';
    }else{
        cout << ans << ' ' << max_time << '\n';
    }
    return 0;
}
