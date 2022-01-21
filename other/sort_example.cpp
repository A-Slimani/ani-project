#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> number_list = {1, 5, 9, 20, 2, 45, 88, 3};

    sort(number_list.begin(), number_list.end());

    for (int x : number_list){
        cout << x << endl;
    }

    return 0;
}