#include "DFS.h"
#include <string>
#include <vector>
#include <sstream>

void DFS::DFS1(int v)
{
    visited[v] = true;
    std::cout << v << " ";

    for(int i = 0; i < neighbors_list.size(); i++)
        if(macierz_sąsiedztwa[v][i] && !visited[i]) {
            DFS1(i);
        }
}
void DFS::macierz_sasiedztwa() {

    for(int i = 0; i < neighbors_list.size(); i++) {
        int a =neighbors_list[i][0]; // pierwsza dana
        if (neighbors_list[i].size() > 1) {
        int b = neighbors_list[i][1];
            macierz_sąsiedztwa[a][b]= true;
            macierz_sąsiedztwa[b][a] = true;
        }
        macierz_sąsiedztwa[a][a] = true;
        // std::vector<bool> visited_places(100);
        // if(!visited_places[i]) {
        //     visited_places[i] = true;
        // }
    }

}


std::vector<int> DFS::split(const std::string& str, char delimiter) {
    std::vector<int> tokens;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        try {
            tokens.push_back(std::stoi(item));
        } catch (const std::exception& e) {
            std::cerr << "Conversion error: " << e.what() << " [string: " << item << "]" << std::endl;
        }
    }
    return tokens;
}

std::vector<std::vector<int>> DFS::readFile() {
    std::fstream file;
    file.open("grafDFSBFS.txt", std::ios::in);
    std::vector<std::vector<int>> neighbour_list;
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (!line.empty()) {
                std::vector<int> tokens = split(line, ' ');
                neighbour_list.push_back(tokens);
            }
        }
        file.close();
    } else {
        std::cerr << "Failed to open file." << std::endl;
    }



    for (int i = 0; i < neighbour_list.size(); i++) {
        searchDFS(visited[i]);
    }

/* //wyswietlanie calego grafu
    for (const auto& tokens : lista_sasiedztwa) {
        if (tokens.size() == 2) {
            std::cout << tokens[0] << " " << tokens[1] << std::endl;
        } else if (!tokens.empty()) {
            std::cout << tokens[0] << std::endl;
        }
    }
    */
    return neighbour_list;
}

void DFS::searchDFS(int x) {
    visited[x] = 1;
    for (int i = 0; i< 0; i++);

}

void DFS::DFSik(int vertex) {
    // Oznacz wierzchołek jako odwiedzony
    visited[vertex] = true;
    std::cout << vertex << " ";  // Wypisanie wierzchołka dla celów demonstracyjnych
    std::vector<std::vector<int>> neighbour_list = readFile();
    // Przechodzenie po sąsiadach wierzchołka
    for (int neighbor : neighbour_list[vertex]) {
        if (!visited[neighbor]) {  // Sprawdzenie, czy sąsiad nie był odwiedzony
            DFSik(neighbor);
        }
    }
}