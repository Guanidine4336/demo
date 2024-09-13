#include<bits/stdc++.h>
using namespace std;

int main()
{
    // Project Overview:
//  -----------------
//  This project aims to improve the efficiency of our train system by implementing
//  Dijkstra's algorithm to find the shortest paths between train stations. By 
//  calculating the optimal routes based on both cost and time, we intend to 
//  enhance the overall performance and passenger satisfaction within the train network.
    
    
    
vector<string> stations = {
    "Lucknow Junction (LJN)",
    "Kanpur Central (CNB)",
    "Varanasi Junction (BSB)",
    "Allahabad Junction (PRYJ)",
    "Gorakhpur Junction (GKP)",
    "Agra Cantt (AGC)",
    "Mathura Junction (MTJ)",
    "Aligarh Junction (ALJN)",
    "Meerut City (MTC)",
    "Moradabad (MB)",
    "Bareilly Junction (BE)",
    "Jhansi Junction (JHS)",
    "Gonda Junction (GD)",
    "Faizabad Junction (FD)",
    "Sultanpur Junction (SLN)",
    "Firozabad (FZD)",
    "Tundla Junction (TDL)",
    "Etawah (ETW)",
    "Shahjahanpur (SPN)",
    "Amethi (AME)",
    "Rae Bareli Junction (RBL)",
    "Ballia (BUI)",
    "Mau Junction (MAU)",
    "Deoria Sadar (DEOS)",
    "Chitrakoot Dham Karwi (CKTD)"
};

    // Print all stations to verify
    for(auto& station : stations) {
        cout << station << endl;
    }
        return 0;
}
