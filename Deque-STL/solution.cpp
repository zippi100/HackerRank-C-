// Deque-STL
#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    //Write your code here.
    deque<int> d;
    //int temp;

    for (int i = 0; i < n; ++i){
        //temp = arr[i];

        // this will work also, just runs in O(n2)
        /*for (int j = i; j < (i + k); ++j){
            if (temp < arr[j]){
                temp = arr[j];
            }
        }*/

        while (!d.empty() && arr[i] > d.back()){
            d.pop_back();
        }
        d.push_back(arr[i]);
        if (i >= k && d.front() == arr[i-k]){
            d.pop_front();
        }
        if (i >= k - 1){
            cout << d.front() << ' ';
        }
        
    }
    cout << endl;

}

int main(){
  
    int t;
    cin >> t;
    while(t>0) {
        int n,k;
        cin >> n >> k;
        int i;
        int arr[n];
        for(i=0;i<n;i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}
