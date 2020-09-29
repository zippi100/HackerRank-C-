// Maps-STL
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int qSize, q, mark;
    string name;
    map<string, int> m;

    cin >> qSize;

    for (int i = 0; i < qSize; ++i){
        cin >> q >> name;

        if (q == 1){
            cin >> mark;

            if (m.find(name) != m.end()){
                m[name] += mark;
            } 
            else{
                m.insert(make_pair(name,mark));
            }

        }
        else if (q == 2){
            m.erase(name);
            m[name] = 0;
        }
        else{
            cout << m[name] << endl;
        }
    }   

    return 0;
}




