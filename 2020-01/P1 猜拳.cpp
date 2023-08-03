#include <iostream>
using namespace std;

int main()
{
    int i, f, n, num[10];
    cin >> f >> n;
    for(i = 0; i < n; i++){
        cin >> num[i];
    }
    int temp = -1;
    for(i = 0; i < n; i++){
        cout << f << ' ';
        if(f == 0){
            if(num[i] == 2){
                cout << ": Won at round " << (i + 1) << '\n';
                break;
            }else if(num[i] == 5){
                cout << ": Lost at round " << (i + 1) << '\n';
                break;
            }
        }else if(f == 2){
            if(num[i] == 5){
                cout << ": Won at round " << (i + 1) << '\n';
                break;
            }else if(num[i] == 0){
                cout << ": Lost at round " << (i + 1) << '\n';
                break;
            }
        }else if(f == 5){
            if(num[i] == 0){
                cout << ": Won at round " << (i + 1) << '\n';
                break;
            }else if(num[i] == 2){
                cout << ": Lost at round " << (i + 1) << '\n';
                break;
            }
        }
        if(temp == num[i]){
            if(temp == 0){
                f = 5;
            }else if(temp == 2){
                f = 0;
            }else if(temp == 5){
                f = 2;
            }
        }else{
            f = num[i];
        }
        temp = num[i];
    }
    if(i == n){
        cout << ": Drew at round " << n << '\n';
    }
    return 0;
}
