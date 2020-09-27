// Pretty- Print
#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
    int T; cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;

        /* Enter your code here */
        long a = A;
        
        cout << nouppercase << setw(0) << left << showbase << hex << a << endl;
        cout << right << setw(15) << setprecision(2) << fixed << showpos << setfill('_') << B << endl;
        cout << uppercase << setprecision(9) << noshowpos << scientific << C << endl; 
    
    }
    return 0;

}
