#include <iostream>
using namespace std;

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    long long ans = 0;
    for(int i = n - k + 1; i <= n; i++){
        ans = (ans + m) % i;
    }
    cout << ans + 1 << '\n';
    return 0;
}
