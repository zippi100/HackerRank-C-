// Vector-Erase
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int vecSize, value, q1, range1, range2;
    vector<int> myVec;

    cin >> vecSize;

    for (int i = 0; i < vecSize; ++i){
        cin >> value;
        myVec.push_back(value);
    }

    cin >> q1 >> range1 >> range2;

    --q1;
    --range1;
    --range2;
    myVec.erase(myVec.begin() + q1);
    

    myVec.erase(myVec.begin() + range1, myVec.begin() + range2);

    cout << myVec.size() << endl;
    for (int i = 0; i < myVec.size(); ++i){
        cout << myVec[i] << ' ';
    }

    return 0;
}

