#ifndef DFS_H
#define DFS_H
#include<string>
#include<vector>
#include <iostream>
#include<fstream>


class DFS {

public:
    bool macierz_sąsiedztwa[100][100];
    std::vector<std::vector<int>> neighbors_list;
    bool visited[100] = {};
    std::vector<int> split(const std::string& str, char delimiter);
    std::vector<std::vector<int>> readFile();
    void searchDFS(int x);
    void DFSik(int vertex);
    void DFS1(int v);
    void macierz_sasiedztwa();

};



#endif //DFS_H
