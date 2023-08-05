#include <iostream>
using namespace std;

pair<int, int> point[101];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> point[i].first >> point[i].second;
    }
    int x = point[0].first, y = point[0].second;
    int left = 0, right = 0, time = 0, side = 0;
    // 0 東 1 西 2 南 3 北
    for(int i = 1; i < n; i++){
        int new_x = point[i].first, new_y = point[i].second;
        if(side == 0){
            if(new_x < x){
                side = 1;
                time += 1;
            }else if(new_y > y){
                side = 3;
                left += 1;
            }else if(new_y < y){
                side = 2;
                right += 1;
            }
        }else if(side == 1){
            if(new_x > x){
                side = 0;
                time += 1;
            }else if(new_y > y){
                side = 3;
                right += 1;
            }else if(new_y < y){
                side = 2;
                left += 1;
            }
        }else if(side == 2){
            if(new_y > y){
                side = 3;
                time += 1;
            }else if(new_x > x){
                side = 0;
                left += 1;
            }else if(new_x < x){
                side = 1;
                right += 1;
            }
        }else if(side == 3){
            if(new_y < y){
                side = 2;
                time += 1;
            }else if(new_x > x){
                side = 0;
                right += 1;
            }else if(new_x < x){
                side = 1;
                left += 1;
            }
        }
        x = new_x, y = new_y;
    }
    cout << left << ' ' << right << ' ' << time << '\n';
    return 0;
}
