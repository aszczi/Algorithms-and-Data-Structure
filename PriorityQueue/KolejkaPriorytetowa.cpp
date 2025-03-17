#include "KolejkaPriorytetowa.h"

#include <iostream>
#include <ostream>


void KolejkaPriorytetowa::insert(int x) {
    int i, j;

    i = number_of_elements++;
    j = (i-1)/2;

    while(i > 0 && T[j] < x)
    {
        T[i] = T[j];
        i = j;
        j = (i-1)/2;
    }

    T[i] = x;
}

int KolejkaPriorytetowa::RemoveRootElem() {
   int root = getRootElem();
        int i, j, v;

        if(number_of_elements--)
        {
            v = T[number_of_elements];
            i = 0;
            j = 1;
            while(j < number_of_elements)
            {
                if(j+1 < number_of_elements && T[j+1] > T[j])
                    j++;
                if(v >= T[j]) break;
                T[i] = T[j];
                i = j;
                j = 2*j+1;
            }
            T[number_of_elements] = 0;
        }
    return root;
}


void KolejkaPriorytetowa::print() {//opcjonalnie dla wyświetlenia kolejnych elementów macierzy, w której trzymany jest kopiec.
    int dzielnik = 1;
    for (int i = 0; i < T.size(); i++) {
        std::cout<< std::string(1.5*T.size()/(dzielnik+1), ' ')  << T[i] << " ";
        if ((i+2)%dzielnik == 0) {
            std::cout << std::endl;
            dzielnik*=2;
        }
    }

}
int KolejkaPriorytetowa::getRootElem() {
    return T[0];
}