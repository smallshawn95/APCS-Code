#include <iostream>
using namespace std;

int main()
{
    int num, time[10] = {0};
    for(int i = 0; i < 3; i++){
        cin >> num;
        time[num] += 1;
    }
    int max = 0;
    for(int i = 0; i < 10; i++){
        if(time[i] > max){
            max = time[i];
        }
    }
    cout << max << ' ';
    for(int i = 9; i > 0; i--){
        if(time[i] > 0){
            cout << i << ' ';
        }
    }
    return 0;
}
