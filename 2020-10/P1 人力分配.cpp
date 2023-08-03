#include <iostream>
using namespace std;

int main()
{
    int A1[3], A2[3], n, ans;
    for (int i = 0; i < 3; i++){
        cin >> A1[i];
    }
    for (int i = 0; i < 3; i++){
        cin >> A2[i];
    }
    cin >> n;
    for (int X1 = 0; X1 <= n; X1++){
        int Y1 = A1[0] * X1 * X1 + A1[1] * X1 + A1[2];
        int Y2 = A2[0] * (n - X1) * (n - X1) + A2[1] * (n - X1) + A2[2];
        if(X1 == 0 || (Y1 + Y2) > ans){
            ans = Y1 + Y2;
        }
    }
    cout << ans << '\n';
    return 0;
}
