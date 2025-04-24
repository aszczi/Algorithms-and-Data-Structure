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
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2){
    matrix[i_Vertex_Index_1 - 1][i_Vertex_Index_2 - 1] = 1;
}

void Graf::addEdge(int i_Vertex_Index_1, int i_Vertex_Index_2, int j) {
  matrix[i_Vertex_Index_1][i_Vertex_Index_2] = j;
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
  //zakladam ze pierwsza liczba to ilosc wierzcholkow jak w przykładowych plikach
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
      case 3:
        addEdge(numbers[0] , numbers[1], numbers[2]);
      break;
    }
  }
  file.close();
}

void Graf::clear(){
  for(int i = 0; i < 100; i++){
    for(int j = 0; j < 100; j++){
      matrix[i][j] = 0;
    }
  }
  numberOfVertices = 0;
}

void Graf::print() {
  for(int i = 0; i < numberOfVertices; i++) {
    std::cout<<"{";
    for(int j = 0; j < numberOfVertices; j++) {
      if (i==j) {
        std::cout<<"0, ";
      }else {
        if (matrix[i][j] == 0) {
          std::cout<<"INF, ";
        }else {
          std::cout << matrix[i][j] << ", ";
        }

      }


    }
    std::cout<<"}, \n";
  }
}

void Graf::FloydWarshallMatrix() {
    const int INF = 1000000;
    int dist[10][10];

    // --- 1) Inicjalizacja macierzy 'dist' z Twojej macierzy 'matrix' ---
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else if (matrix[i][j] == 0) {
                // zero poza przekątną = brak krawędzi
                dist[i][j] = INF;
            }
            else {
                dist[i][j] = matrix[i][j];
            }
        }
    }

    // --- 2) Właściwy algorytm Floyd–Warshalla ---
    for (int k = 0; k < numberOfVertices; ++k) {
        for (int i = 0; i < numberOfVertices; ++i) {
            for (int j = 0; j < numberOfVertices; ++j) {
                // jeśli istnieje ścieżka i–>k oraz k–>j
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    int przezK = dist[i][k] + dist[k][j];
                    if (przezK < dist[i][j])
                        dist[i][j] = przezK;
                }
            }
        }
    }

    // --- 3) Wyświetlanie wyniku ---
    for (int i = 0; i < numberOfVertices; ++i) {
        for (int j = 0; j < numberOfVertices; ++j) {
            if (dist[i][j] == INF)
                std::cout << "INF ";
            else
                std::cout << dist[i][j] << " ";
        }
        std::cout << "\n";
    }
}