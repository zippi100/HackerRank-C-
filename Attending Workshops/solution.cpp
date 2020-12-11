// Attending Workshops
#include<bits/stdc++.h>

using namespace std;

#include <vector>
#include <algorithm>
//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int startTime;
    int duration;
    int endTime;
};
struct Available_Workshops{
    int n;
    vector<Workshops> workshops;
};

Available_Workshops *initialize(int start[], int dur[], int n){
    Available_Workshops *a = new Available_Workshops;
    a->n = n;
    Workshops workshop;
    for (int i = 0; i < n; ++i){
        workshop.startTime = start[i];
        workshop.duration  = dur[i];
        workshop.endTime   = start[i] + dur[i];
        a->workshops.push_back(workshop);
    }
    return a;   
}

int CalculateMaxWorkshops(Available_Workshops *ptr){
    sort(ptr->workshops.begin(), ptr->workshops.end(),[] (Workshops A, Workshops B){
        return A.endTime < B.endTime;
    });

    int count = 0, currentTime = 0;

    for (int i = 0; i < ptr->n; ++i){
        if (ptr->workshops[i].startTime >= currentTime){
            ++count;
            currentTime = ptr->workshops[i].endTime;
        }
    }
    return count;
}


int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

