#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define the number of nodes (stations)
const int N = 25;

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

// Define large value as infinity
const int INF = 1e9;

// Adjacency matrices for time and cost
vector<vector<int>> timeMatrix(N, vector<int>(N, INF));
vector<vector<int>> costMatrix(N, vector<int>(N, INF));
vector<vector<int>> predecessor(N, vector<int>(N, -1));

// Initialize the diagonal elements to zero
void initializeMatrices() {
    for (int i = 0; i < N; ++i) {
        timeMatrix[i][i] = 0;
        costMatrix[i][i] = 0;
    }
}

// Function to add edges to the matrices
void addEdge(int u, int v, int time, int cost) {
    timeMatrix[u][v] = time;
    timeMatrix[v][u] = time;
    costMatrix[u][v] = cost;
    costMatrix[v][u] = cost;
    predecessor[u][v] = u;
    predecessor[v][u] = v;
}

// Floyd-Warshall algorithm for finding shortest paths
void floydWarshall(vector<vector<int>>& matrix, vector<vector<int>>& pred) {
    for (int k = 0; k < N; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (matrix[i][k] < INF && matrix[k][j] < INF && matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}

// Function to reconstruct the path from source to destination
vector<int> reconstructPath(int src, int dest, const vector<vector<int>>& pred) {
    vector<int> path;
    for (int at = dest; at != -1; at = pred[src][at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    if (path[0] == src) {
        return path;
    }
    return {}; // Return an empty path if there's no valid path
}

int main() {
    initializeMatrices();

    // Example edges with time and cost (u, v, time, cost)
    addEdge(0, 1, 72, 150);   // Lucknow Junction to Kanpur Central
    addEdge(1, 2, 320, 600);  // Kanpur Central to Varanasi Junction
    addEdge(2, 3, 120, 250);  // Varanasi Junction to Allahabad Junction
    addEdge(3, 4, 90, 400);  // Allahabad Junction to Gorakhpur Junction
    addEdge(4, 5, 90, 200);   // Gorakhpur Junction to Agra Cantt
    addEdge(5, 6, 50, 100);   // Agra Cantt to Mathura Junction
    addEdge(6, 7, 40, 80);    // Mathura Junction to Aligarh Junction
    addEdge(7, 8, 100, 220);  // Aligarh Junction to Meerut City
    addEdge(8, 9, 120, 250);  // Meerut City to Moradabad
    addEdge(9, 10, 90, 180);  // Moradabad to Bareilly Junction
    addEdge(10, 11, 150, 300);// Bareilly Junction to Jhansi Junction
    addEdge(11, 12, 200, 400);// Jhansi Junction to Gonda Junction
    addEdge(12, 13, 130, 260);// Gonda Junction to Faizabad Junction
    addEdge(13, 14, 80, 160); // Faizabad Junction to Sultanpur Junction
    addEdge(14, 15, 110, 220);// Sultanpur Junction to Firozabad
    addEdge(15, 16, 70, 140); // Firozabad to Tundla Junction
    addEdge(16, 17, 60, 120); // Tundla Junction to Etawah
    addEdge(17, 18, 90, 180); // Etawah to Shahjahanpur
    addEdge(18, 19, 100, 200);// Shahjahanpur to Amethi
    addEdge(19, 20, 110, 220);// Amethi to Rae Bareli Junction
    addEdge(20, 21, 150, 300);// Rae Bareli Junction to Ballia
    addEdge(21, 22, 140, 280);// Ballia to Mau Junction
    addEdge(22, 23, 160, 320);// Mau Junction to Deoria Sadar
    addEdge(23, 24, 170, 340);// Deoria Sadar to Chitrakoot Dham Karwi

    // Additional random edges
    addEdge(0, 2, 250, 500);   // Lucknow Junction to Varanasi Junction
    addEdge(3, 5, 210, 420);   // Allahabad Junction to Agra Cantt
    addEdge(1, 6, 150, 300);   // Kanpur Central to Mathura Junction
    addEdge(4, 7, 230, 460);   // Gorakhpur Junction to Aligarh Junction
    addEdge(8, 11, 200, 400);  // Meerut City to Jhansi Junction
    addEdge(9, 12, 170, 340);  // Moradabad to Gonda Junction
    addEdge(10, 13, 190, 380); // Bareilly Junction to Faizabad Junction
    addEdge(11, 14, 210, 420); // Jhansi Junction to Sultanpur Junction
    addEdge(12, 15, 220, 440); // Gonda Junction to Firozabad
    addEdge(13, 16, 240, 480); // Faizabad Junction to Tundla Junction
    addEdge(14, 17, 250, 500); // Sultanpur Junction to Etawah
    addEdge(15, 18, 270, 540); // Firozabad to Shahjahanpur
    addEdge(16, 19, 260, 520); // Tundla Junction to Amethi
    addEdge(17, 20, 290, 580); // Etawah to Rae Bareli Junction
    addEdge(18, 21, 310, 620); // Shahjahanpur to Ballia
    addEdge(19, 22, 320, 640); // Amethi to Mau Junction
    addEdge(20, 23, 340, 680); // Rae Bareli Junction to Deoria Sadar
    addEdge(21, 24, 350, 700); // Ballia to Chitrakoot Dham Karwi

    // Apply Floyd-Warshall algorithm to both time and cost matrices
    floydWarshall(timeMatrix, predecessor);
    floydWarshall(costMatrix, predecessor);

    // Print shortest times
    cout << "Shortest times between all pairs of stations:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (timeMatrix[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << timeMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    // Print shortest costs
    cout << "\nShortest costs between all pairs of stations:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (costMatrix[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << costMatrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    // // Example of reconstructing the path from source to destination
    // int src = 0;  // Lucknow Junction (LJN)
    // int dest = 4; // Gorakhpur Junction (GKP)
    int src = 0, dest = 0;
    cout << "ENTER A SOURCE STATION: ";
    cin >> src;
    cout << "ENTER A DESTINATION STATION: ";
    cin >> dest;
    vector<int> path = reconstructPath(src, dest, predecessor);

    if (!path.empty()) {
        cout << "\nShortest w.r.t pathtime from " << stations[src] << " to " << stations[dest] << ":\n";
        for (int i : path) {
            cout << stations[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No path exists from " << stations[src] << " to " << stations[dest] << endl;
    }

    return 0;
}
