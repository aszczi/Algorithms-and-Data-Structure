#include "Graf.h"



void test()
{
    Graf* G = new Graf();
    G->readFromFile("C:\\Users\\asias\\CLionProjects\\uGrafMacierzSasiedztwa\\grafZadanie.txt");
    G->print();
    G->FloydWarshallMatrix();
}

int main()
{
 
    test();
}




