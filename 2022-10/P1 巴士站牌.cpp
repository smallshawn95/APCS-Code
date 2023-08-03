#include <iostream>
using namespace std;

int main()
{
    int n, x[101], y[101];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    int max = 0, min = 1000;
    for(int i = 0; i < n - 1; i++){
        int far = abs(x[i] - x[i + 1]) + abs(y[i] - y[i + 1]);
        if(far > max){
            max = far;
        }
        if(far < min){
            min = far;
        }
    }
    cout << max << ' ' << min << '\n';
    return 0;
}
