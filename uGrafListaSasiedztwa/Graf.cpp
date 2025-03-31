#include "Graf.h"
Graf::Graf() {
  vertexList.clear();
}

void Graf::createVertices(int ile) {
  vertexList = std::vector<std::vector<edge>>(ile + 1);
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){

  vertexList[i_Vertex_Index_1].push_back(edge(i_Vertex_Index_1, i_Vertex_Index_2));

}

void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
  for(int i=0;i<vertexList[i_Vertex_Index_1].size();i++){
      if(vertexList[i_Vertex_Index_1][i].vertex_Index2 == i_Vertex_Index_2){
            vertexList[i_Vertex_Index_1].erase(vertexList[i_Vertex_Index_1].begin() + i);
            break;
      }
  }
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
  bool result = false;
  for(int i=0;i<vertexList[i_Vertex_Index_1].size();i++){
    if(vertexList[i_Vertex_Index_1][i].vertex_Index2 == i_Vertex_Index_2){
      result = true;
      break;
    }
  }
return result;
}


int Graf::vertexDegree(int idx){
  return vertexList[idx].size();
}

// w vertex list mamy tylko i wylacznie polaczenia dla indexu
std::vector<int> Graf::getNeighbourIndices(int idx){

  std::vector<int> indices;
  for(int i = 0; i < vertexList[idx].size(); i++){
       indices.push_back(vertexList[idx][i].vertex_Index2);
  }
  std::sort(indices.begin(), indices.end());
  return indices;
}


void Graf::printNeighbourIndices(int idx){
  std::vector<int> indices = getNeighbourIndices(idx);
  std::cout<<"Neighbour indices for "<<idx<<" : ";
  for(int i = 0; i < indices.size(); i++){
    std::cout << indices[i] << " ";
  }
  std::cout<<std::endl;
}

int Graf::getNumberOfEdges(){
  int numberOfEdges = 0;
  for(int i = 1; i < vertexList.size(); i++){
    numberOfEdges += vertexList[i].size();
  }
  return numberOfEdges;
}


void Graf::readFromFile(std::string path){
   int number_of_elements = 0;
   std::ifstream file(path);
        if (!file.is_open()) {
            std::cerr << "Nie można otworzyć pliku: " << path << std::endl;
            return;
        }

      std::string line;
      // Odczytujemy plik linia po linii
      while (std::getline(file, line)) {

        std::istringstream iss(line);
        std::vector<int> numbers;
        int num;

        while (iss >> num) {
          numbers.push_back(num);
        }

        switch (numbers.size()) {
          case 1:
            createVertices(numbers[0]);
          break;
          case 2:
            addEdge(numbers[0] , numbers[1]);
          break;

        }

     }

    file.close();
}