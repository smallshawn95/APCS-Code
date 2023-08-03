#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int side[3];
    for (int i = 0; i < 3; i++)
            cin >> side[i];
    sort(side, side + 3);
    for (int i = 0; i < 3; i++)
        cout << side[i] << ' ';
    cout << endl;
    if (side[0] + side[1] > side[2]){
        if (pow(side[0], 2) + pow(side[1], 2) < pow(side[2], 2))
            cout << "Obtuse" << endl;
        else if (pow(side[0], 2) + pow(side[1], 2) == pow(side[2], 2))
            cout << "Right" << endl;
        else if (pow(side[0], 2) + pow(side[1], 2) > pow(side[2], 2))
            cout << "Acute" << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}
