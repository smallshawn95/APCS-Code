#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b;
    string data[9][5];
    for(int i = 0; i < 9; i++){
        cin >> a;
        for(int j = 0; j < a; j++){
            cin >> data[i][j];
        }
    }
    cin >> b;
    int out = 0, idx_i = 0, idx_j = 0, grade = 0;
    int base[4] = {0, 0, 0, 0};
    while(b){
        string choice = data[idx_i][idx_j];
        if(choice == "1B"){
            for(int i = 3; i >= 1; i--){
                if(base[i - 1] == 1){
                    base[i] += 1;
                    base[i - 1] = 0;
                }
            }
            base[0] += 1;
        }else if(choice == "2B"){
            for(int i = 1; i < 3; i++){
                if(base[i] == 1){
                    base[i] = 0;
                    base[3] += 1;
                }
            }
            if(base[0] == 1){
                base[0] = 0;
                base[2] = 1;
            }
            base[1] += 1;
        }else if(choice == "3B"){
            for(int i = 0; i < 3; i++){
                if(base[i] == 1){
                    base[i] = 0;
                    base[3] += 1;
                }
            }
            base[2] += 1;
        }else if(choice == "HR"){
            for(int i = 0; i < 3; i++){
                if(base[i] == 1){
                    base[i] = 0;
                    base[3] += 1;
                }
            }
            base[3] += 1;
        }else if(choice == "FO" || choice == "GO" || choice == "SO"){
            out += 1;
            b -= 1;
        }
        grade += base[3];
        base[3] = 0;
        if(idx_i == 8){
            idx_i = 0;
            idx_j += 1;
        }else{
            idx_i += 1;
        }
        if(out == 3){
            out = 0;
            for(int i = 0; i < 4; i++){
                base[i] = 0;
            }
        }
    }
    cout << grade << '\n';
    return 0;
}
