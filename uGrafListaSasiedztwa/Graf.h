#ifndef GRAF_H
#define GRAF_H
#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include "edge.h"


class Graf
{
    std::vector<std::vector<edge>> vertexList;


public:
    Graf();
    void createVertices(int ile);
    void addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    void removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    bool checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2);
    int vertexDegree(int idx);
    std::vector<int> getNeighbourIndices(int idx);
    void printNeighbourIndices(int idx);
    int getNumberOfEdges();
    void readFromFile(std::string path);
};



#endif //GRAF_H
