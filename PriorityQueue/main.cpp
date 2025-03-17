#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "KolejkaPriorytetowa.h"

KolejkaPriorytetowa kolejka;

int main()
{
    srand(time(NULL));

    std::cout<<"Drawn elements: "<<std::endl;

    for(int i = 0; i < 31; i++)
    {
        int x = rand() % 100;
        std::cout << x << " ";
        kolejka.insert(x);
    }

    std::cout<<"\nVisual representation of heap :\n\n";
    kolejka.print();
    std::cout<<"\nGet root element :"<<kolejka.getRootElem()<<std::endl;
    std::cout<<"\nRemove root element: " <<kolejka.RemoveRootElem()<<std::endl;
    std::cout<<"\nHeap after removing root: \n";
    kolejka.print();

    return 0;
}