// Sets-STL
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int qSize, q, value;
    set<int> s;
    
    cin >> qSize;

    for (int i = 0; i < qSize; ++i){
        cin >> q >> value;

        if (q == 1){
            s.insert(value);
        }
        else if (q == 2){
            s.erase(value);
        }
        else if (q == 3){
            set<int>::iterator it = s.find(value);

            if(it != s.end()){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}




