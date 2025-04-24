# 0 "C:/Users/asias/CLionProjects/uGrafMacierzSasiedztwa/edge.cpp"
# 1 "C:\\Users\\asias\\CLionProjects\\uGrafMacierzSasiedztwa\\cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "C:/Users/asias/CLionProjects/uGrafMacierzSasiedztwa/edge.cpp"
# 1 "C:/Users/asias/CLionProjects/uGrafMacierzSasiedztwa/edge.h" 1



struct edge
{
    int vertex_Index1;
    int vertex_Index2;
    float waga;

public:
    edge(int i_Vertex_Index1, int i_Vertex_Index2);
    edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight);
};
# 2 "C:/Users/asias/CLionProjects/uGrafMacierzSasiedztwa/edge.cpp" 2

edge::edge(int i_Vertex_Index1, int i_Vertex_Index2)
{
    vertex_Index1 = i_Vertex_Index1;
    vertex_Index2 = i_Vertex_Index2;
    waga = 0;
}

edge::edge(int i_Vertex_Index_1, int i_Vertex_Index_2, float i_weight)
{
    vertex_Index1 = i_Vertex_Index_1;
    vertex_Index2 = i_Vertex_Index_2;
    waga = i_weight;
}
