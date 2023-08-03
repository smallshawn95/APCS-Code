#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x[n];
    bool best = 1, worst = 1;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x, x + n);
    cout << x[0];
    for(int i = 1; i < n; i++){
        cout << " " << x[i];
    }
    cout << '\n';
    int min, max;
    for(int j = 0; j < n; j++){
        if(x[j] < 60){
            min = x[j];
            best = 0;
        }
        if(x[j] >= 60){
            max = x[j];
            worst = 0;
            break;
        }
    }
    if(best){
        cout << "best case\n";
    }else{
        cout << min << '\n';
    }
    if(worst){
        cout << "worst case\n";
    }else{
        cout << max << '\n';
    }
    return 0;
}
