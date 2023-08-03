#include <iostream>
#include <string>
using namespace std;

string fun[101];

int main()
{
    int n, m;
    string str;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> fun[i];
    }
    cin >> str;
    for(int i = n - 1; i >= 0; i--){
        int one = 0, x = 0, y = m - 1;
        char t[m + 1];
        for(int j = 0; j < m; j++){
            if(fun[i][j] == '1'){
                one += 1;
                t[y--] = str[j];
            }else if(fun[i][j] == '0'){
                t[x++] = str[j];
            }
        }
        if(one % 2 == 1){
            string a = "", b = "";
            for(int j = 0; j < m / 2; j++){
                a += t[j];
                b += t[j + (m + 1) / 2];
            }
            str = (m % 2 == 1 ? b + t[m / 2] + a : b + a);
        }else{
            str = t;
        }
    }
    cout << str << '\n';
    return 0;
}
