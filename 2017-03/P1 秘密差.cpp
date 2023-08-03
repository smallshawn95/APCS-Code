#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    string str;
    while(cin >> str){
        int a = 0, b = 0, x;
        x = str.length();
        for(int i = 0; i < x; i++){
            if(i % 2 == 0){
                a = a + str[i] - '0';
            }else{
                b = b + str[i] - '0';
            }
        }
        cout << abs(a - b) << '\n';
    }
    return 0;
}
