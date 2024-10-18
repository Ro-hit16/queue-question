#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct petrolPump{
    int petrol;
    int distance;
};
int tour( petrolPump p[],int n){
    int totalPetrol =0;
    int totalDistance =0;
    int currPetrol = 0;
    int start = 0;

    for(int i=0;i<n;i++){
        totalDistance += p[i].distance;
        totalPetrol += p[i].distance;
        currPetrol += p[i].petrol -p[i].distance;

        if(currPetrol <0){
            start = i+1;
            currPetrol =0;
        }
    }
    if(totalPetrol < totalDistance){
        return -1;
    }
    return start;
}
int main(){
petrolPump p[] = {{6, 4}, {3, 6}, {7, 3}, {4, 5}};
    int n = sizeof(p) / sizeof(p[0]);

    // Find the starting point for the circular tour
    int start = tour(p, n);

    if (start == -1) {
        cout << "No solution possible" << endl;
    } else {
        cout << "Start the tour from petrol pump: " << start << endl;
    }
return 0;
}