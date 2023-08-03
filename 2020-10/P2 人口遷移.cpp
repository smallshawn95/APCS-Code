#include <iostream>
using namespace std;

int main()
{
    int r, c, k, m, max, min;
    cin >> r >> c >> k >> m;
    int num[r + 2][c + 2];
    for(int i = 0; i < r + 2; i++){
        for(int j = 0; j < c + 2; j++){
            if(i == 0 || i == r + 1 || j == 0 || j == c + 1){
                num[i][j] = -1;
            }else{
                cin >> num[i][j];
            }
        }
    }
    while(m--){
        int temp[52][52] = {0};
        for(int i = 1; i <= r + 1; i++){
            for(int j = 1; j <= c + 1; j++){
                int people = num[i][j] / k;
                if(num[i - 1][j] != -1){
                    temp[i][j] -= people;
                    temp[i - 1][j] += people;
                }
                if(num[i + 1][j] != -1){
                    temp[i][j] -= people;
                    temp[i + 1][j] += people;
                }
                if(num[i][j + 1] != -1){
                    temp[i][j] -= people;
                    temp[i][j + 1] += people;
                }
                if(num[i][j - 1] != -1){
                    temp[i][j] -= people;
                    temp[i][j - 1] += people;
                }
            }
        }
        max = 0;
        min = 10000;
        for(int i = 1; i < r + 1; i++){
            for(int j = 1; j < c + 1; j++){
                num[i][j] += temp[i][j];
                if(num[i][j] != -1){
                    if(num[i][j] > max){
                        max = num[i][j];
                    }
                    if(num[i][j] < min){
                        min = num[i][j];
                    }
                }
            }
        }
    }
    cout << min << '\n' << max << '\n';
    return 0;
}
