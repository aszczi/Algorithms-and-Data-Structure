#include "Graf.h"


Graf::Graf(){
  numberOfVertices = 0;
  for(int i = 0; i < 100; i++) {
    for(int j = 0; j < 100; j++) {
      matrix[i][j] = 0;
    }
  }

 }
void Graf::createVertices(int ile){
  numberOfVertices = ile;
  //create
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    matrix[i_Vertex_Index_1 - 1][i_Vertex_Index_2 - 1] = 1;
}


void Graf::removeEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
  matrix[i_Vertex_Index_1 - 1][i_Vertex_Index_2 - 1] = 0;
}

bool Graf::checkEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
  return matrix[i_Vertex_Index_1 - 1][i_Vertex_Index_2 - 1];
}

int Graf::vertexDegree(int idx){
  int result = 0;
   for(int i = 0; i < numberOfVertices; i++){
     result += matrix[idx-1][i];
   }
  return result;
 }
std::vector<int> Graf::getNeighbourIndices(int idx){
  std::vector<int> result;
  for(int i = 1; i <= numberOfVertices; i++){
    if(matrix[idx-1][i-1] == 1){
      result.push_back(i);
    }
  }
  return result;
 }

void Graf::printNeighbourIndices(int idx){
  std::vector<int> neighbourIndices = getNeighbourIndices(idx);
  std::cout<<"Neighbour indices for "<<idx<<" : ";
    for(int e: neighbourIndices){
     std::cout << e << " ";
    }
    std::cout<<std::endl;
 }
int Graf::getNumberOfEdges(){
  int result = 0;
  for(int i = 0; i < numberOfVertices; i++){
    for(int j = 0; j < numberOfVertices; j++){
        result += matrix[i][j];
    }
  }
  return result;
}

void Graf::readFromFile(std::string path){
  //zakladam ze pierwsza liczba to ilosc wierzcholkow
  int number_of_elements = 0;
  std::ifstream file(path);
  if (!file.is_open()) {
    std::cerr << "Nie można otworzyć pliku: " << path << std::endl;
    return;
  }

  std::string line;

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