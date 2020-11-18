//
// Created by Bonjour on 03/12/2018.
//

#include <iostream>
#include <cstdio>
#include "Sommet.hpp"

template <class I, class P> Sommet<I, P>::~Sommet() {
    delete identifiant;
    delete lesVoisins;
}

template <class I, class P> Couple<I, P>* Sommet<I, P>::rechercherVoisins(I *nomSommet, P *poids) {
    if (nomSommet && poids) {
        if (lesVoisins) {
            typename std::vector<Couple<I, P>*>::iterator it;
            for (it = lesVoisins->begin(); it != lesVoisins->end() ; ++it) {
                if (*nomSommet == *it.operator*()->getSommet() && *poids == *it.operator*()->getPoids())
                    return it.operator*();
            }
        }
    }
    return NULL;
}

template <class I, class P> bool Sommet<I, P>::ajouterVoisin(I *&nomSommet, P *&poids) {
    Couple<I ,P> *tmp = rechercherVoisins(nomSommet, poids);
    if (!tmp) {
//        tmp = new Couple<I, P>(nomSommet, poids);
        if (!lesVoisins)
            lesVoisins = new std::vector<Couple<I, P> *>;
        lesVoisins->push_back(new Couple<I, P>(nomSommet, poids));
        delete tmp;
        return true;
    }
    delete tmp;
    return false;
}

template <class I, class P> bool Sommet<I, P>::ajouterVoisin(Couple<I, P> *&couple) {
    Couple<I ,P> *tmp = rechercherVoisins(couple->getSommet(), couple->getPoids());
    if (!tmp) {
        if (!lesVoisins)
            lesVoisins = new std::vector<Couple<I, P> *>;
        lesVoisins->push_back(couple);
        return true;
    }
    return false;
}

template <class I, class P> bool Sommet<I, P>::supprimerVoisin(I *&nomSommet, P *&poids) {
    if (nomSommet && poids) {
        if (lesVoisins) {
            typename std::vector<Couple<I, P>*>::iterator it;
            for (it = lesVoisins->begin(); it != lesVoisins->end() ; ++it) {
                if (*nomSommet == *it.operator*()->getSommet() && *poids == *it.operator*()->getPoids()) {
                    lesVoisins->erase(it);
                    if (lesVoisins->empty())
                        lesVoisins = NULL;
                    return true;
                }
            }
        }
    }
    return false;
}

template <class I, class P> bool Sommet<I, P>::supprimerVoisin(Couple<I, P> *&couple) {
    if (couple && couple->getSommet() && couple->getPoids()) {
        if (lesVoisins) {
            typename std::vector<Couple<I, P>*>::iterator it;
            for (it = lesVoisins->begin(); it != lesVoisins->end() ; ++it) {
                if (*couple->getSommet() == *it.operator*()->getSommet() && *couple->getPoids() == *it.operator*()->getPoids()) {
                    lesVoisins->erase(it);
                    if (lesVoisins->empty())
                        lesVoisins = NULL;
                    return true;
                }
            }
        }
    }
    return false;
}

template <class I, class P> void Sommet<I, P>::afficher() {
    if (identifiant) {
        std::cout << *identifiant + " -> ";
        if (lesVoisins) {
            typename std::vector<Couple<I, P>*>::iterator it;
            for (it = lesVoisins->begin(); it != lesVoisins->end() ; ++it) {
                if (it.operator*()->getSommet()) {
                    std::cout << "(" + *it.operator*()->getSommet() + " -- ";
                    std::cout << *it.operator*()->getPoids();
                    std::cout << "), ";
                } else
                    std::cout << "couple vide" << std::endl;
            }
            std::cout << std::endl;
        } else
            std::cout << "pas de voisins" << std::endl;
    } else
        std::cout << "sommet vide" << std::endl;
}

template class Sommet<std::string, int>;
