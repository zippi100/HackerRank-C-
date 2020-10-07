// Lower Bound-STL
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int vSize, qSize, q, value;
    vector<int> v;
    vector<int>::iterator low, up;

    cin >> vSize;

    for (int i = 0; i < vSize; ++i){
        cin >> value;
        v.push_back(value);
    }
    
    cin >> qSize;

    for (int i = 0; i < qSize; ++i){
        cin >> q;
        /*if (find(v.begin(), v.end(), q) != v.end()){
            low = lower_bound(v.begin(), v.end(), q);
            cout << "Yes " << (low - v.begin()) + 1 << endl;
        }
        else {
            up = upper_bound(v.begin(), v.end(), q);
            cout << "No " << (up - v.begin()) + 1 << endl;
        }*/
        low = lower_bound(v.begin(), v.end(), q);
        if (v[low - v.begin()] == q)
        {
            cout << "Yes " << (low - v.begin()) + 1 << endl;
        }
        else{
            up = upper_bound(v.begin(), v.end(), q);
            cout << "No " << (up - v.begin()) + 1 << endl;
        }
    }
    return 0;
}

