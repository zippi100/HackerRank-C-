Vector-sort
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,m;
    vector<int> list;

    cin >> n;

    for (int i = 0; i < n; ++i){
        cin >> m;
        list.push_back(m);
    }

    sort(list.begin(),list.end());

    for (int i = 0; i < n; ++i){
        cout << list[i] << ' ';
    }

    return 0;
}

