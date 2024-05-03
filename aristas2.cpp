#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

using namespace std;

const int MAX_NODES = 6; // Número total de nodos
const int EDGE_WEIGHT = 1; // Peso en todas las aristas

vector<vector<int>> adjacencyMatrix(MAX_NODES, vector<int>(MAX_NODES, 0));
unordered_set<int> visited;

void DFS(int start, int target, vector<int>& path, vector<int>& shortestPath) {
    visited.insert(start);
    path.push_back(start);
    if (start == target) {
        if (path.size() < shortestPath.size()) {
            shortestPath = path;
        }
        return;
    }
    for (int i = 0; i < MAX_NODES; ++i) {
        if (adjacencyMatrix[start][i] && visited.find(i) == visited.end()) {
            DFS(i, target, path, shortestPath);
        }
    }
    path.pop_back();
    visited.erase(start);
}

int main() {
    // Agregar bordes al grafo (matriz de adyacencia)
    adjacencyMatrix[0][1] = EDGE_WEIGHT; // a -> b
    adjacencyMatrix[1][2] = EDGE_WEIGHT; // b -> c
    adjacencyMatrix[2][3] = EDGE_WEIGHT; // c -> d
    adjacencyMatrix[2][4] = EDGE_WEIGHT; // c -> e
    adjacencyMatrix[4][5] = EDGE_WEIGHT; // e -> f
    adjacencyMatrix[3][5] = EDGE_WEIGHT; // d -> f

    cout << "Matriz de adyacencia:" << endl;
    for (int i = 0; i < MAX_NODES; ++i) {
        for (int j = 0; j < MAX_NODES; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    char start, end;
    cout << "Ingrese el nodo de inicio: ";
    cin >> start;
    cout << "Ingrese el nodo objetivo: ";
    cin >> end;

    vector<int> path, shortestPath(MAX_NODES, numeric_limits<int>::max());
    DFS(start - 'a', end - 'a', path, shortestPath);

    cout << "El recorrido mas corto es: ";
    for (int node : shortestPath) {
        cout << char('a' + node) << " ";
    }
    cout << endl;

    return 0;
}
