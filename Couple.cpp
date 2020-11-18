//
// Created by Bonjour on 03/12/2018.
//

#include <iostream>
#include "Couple.hpp"

template <class I, class P> void Couple<I, P>::afficher() {
    if (sommet && poids) {
        std::cout << "(" + *sommet + " -- ";
        std::cout << *poids;
        std::cout << "), ";
    } else
        std::cout << "couple vide" << std::endl;
}

template <class I, class P> Couple<I, P>::~Couple() {
    delete sommet;
    delete poids;
}

template class Couple<std::string, int>;