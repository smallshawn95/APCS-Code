#include <iostream>
#include <string>
using namespace std;

char ans[30][30];
char temp[30];

int main()
{
    int n, q, r;
    string str;
    cin >> n >> q >> r;
    cin >> str;
    for(int i = 0; i < q; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            ans[i][num - 1] = str[j];
            temp[num - 1] = str[j];
        }
        str = temp;
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < q; j++){
            cout << ans[j][i];
        }
    }
    return 0;
}
