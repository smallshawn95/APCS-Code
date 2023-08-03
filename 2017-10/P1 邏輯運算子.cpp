#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a){
            a = 1;
        }
        if(b){
            b = 1;
        }
        bool no = 1;
        if((a && b) == c){
            cout << "AND\n";
            no = 0;
        }
        if((a || b) == c){
            cout << "OR\n";
            no = 0;
        }
        if((a ^ b) == c){
            cout << "XOR\n";
            no = 0;
        }
        if(no){
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
