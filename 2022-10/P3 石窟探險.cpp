#include <iostream>
using namespace std;

long long f(long long x)
{
    long long n;
    cin >> n;
    if(n == 0){
        return 0;
    }
    long long add = 0;
    if(x != -1){
        add = abs(x - n);
    }
    if(n % 2 == 0){
        return add + f(n) + f(n);
    }else{
        return add + f(n) + f(n) + f(n);;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << f(-1) << '\n';
    return 0;
}
