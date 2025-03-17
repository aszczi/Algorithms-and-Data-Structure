//#pragma once
#include <array>

#ifndef KOLEJKAPRIORYTETOWA_H
#define KOLEJKAPRIORYTETOWA_H



class KolejkaPriorytetowa {


    int number_of_elements=0;

public:
    std::array<int,31> T;
    void insert(int x);
    int RemoveRootElem();
    void print();   //opcjonalnie dla wyświetlenia kolejnych elementów macierzy, w której trzymany jest kopiec.
    int getRootElem();
};



#endif //KOLEJKAPRIORYTETOWA_H
