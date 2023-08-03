#include <iostream>
using namespace std;

int main()
{
    int a, b, n, time = 0;
    cin >> a >> b >> n;
    for(int i = 0; i < n; i++){
        int num, buy_a = 0, buy_b = 0;
        while(cin >> num){
            if(num == 0){
                break;
            }
            if(num == a){
                buy_a += 1;
            }else if(num == -a){
                buy_a -= 1;
            }else if(num == b){
                buy_b += 1;
            }else if(num == -b){
                buy_b -= 1;
            }
        }
        if(buy_a && buy_b){
            time += 1;
        }
    }
    cout << time << '\n';
    return 0;
}
