// Attribute Parser
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,q;
    
    string temp;
    
    vector<string> hrml;
    vector<string> queries;
    vector<string> tag;

    map<string, string> mp;
    
    cin >> n >> q;
    cin.ignore();
    
    for (int i = 0; i < n; ++i){
        getline(cin, temp);
        hrml.push_back(temp);
    }

    for (int i = 0; i < q; ++i){
        getline(cin, temp);
        queries.push_back(temp);
    }

    for (int i = 0; i < n; ++i){
        temp = hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end());

        if (temp[1] == '/'){
            tag.pop_back();
        }
        else{
            stringstream ss;
            ss.str("");
            ss << temp;
            string t, a, v;
            char c;

            ss >> c >> t >> a >> c >> v;
            string temp2 = "";
            
            if(tag.size() > 0){
                temp2 = *tag.rbegin();
                temp2 = temp2 + "." + t;
            }
            else{
                temp2 = t;
            }

            tag.push_back(temp2);
            mp[*tag.rbegin() + "~" + a] = v;

            while (ss){
                ss >> a >> c >> v;
                mp[*tag.rbegin() + "~" + a] = v;
            }


        }
    }

    for (int i = 0; i < q; ++i){
        if (mp.find(queries[i]) != mp.end()){
            cout << mp[queries[i]] << endl;
        }
        else {
            cout << "Not Found!" << endl;
        }
    }


    return 0;
}

