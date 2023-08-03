#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, d, num[3], time = 0, sum = 0;
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> num[j];
        }
        sort(num, num + 3);
        if(num[2] - num[0] >= d){
            time += 1;
            sum += (num[0] + num[1] + num[2]) / 3;
        }
    }
    cout << time << ' ' << sum << '\n';
    return 0;
}
