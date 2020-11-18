//
// Created by Bonjour on 03/12/2018.
//

#include <iostream>
#include <cstdio>
#include "Graphe.hpp"

template <class I, class A> Graphe<I, A>::~Graphe() {
    delete lesSommets;
}

template <class I, class P>
Sommet<I, P>* Graphe<I, P>::rechercher(Sommet<I, P> *sommet) {
    if (sommet) {
        if (lesSommets) {
            typename std::vector<Sommet<I, P>*>::iterator it;
            for (it = lesSommets->begin(); it != lesSommets->end(); ++it) {
                if (*sommet->getIdentifiant() == *it.operator*()->getIdentifiant())
                    return it.operator*();
            }
        }
    }
    return NULL;
}

template <class I, class P>
bool Graphe<I, P>::ajouterSommet(Sommet<I, P> *&sommet) {
    Sommet<I, P> *tmp = rechercher(sommet);
    if (!tmp) {
        if (!lesSommets)
            lesSommets = new std::vector<Sommet<I, P>*>;
        lesSommets->push_back(sommet);
        delete tmp;////////////////////////////////////////////////////////////////////////////////////////////////////////////
        return true;
    }
//    delete tmp;////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    return false;
}

template <class I, class P>
bool Graphe<I, P>::supprimerSommet(Sommet<I, P> *&sommet) {
    if (sommet) {
        if (lesSommets) {
            typename std::vector<Sommet<I, P> *>::iterator it;
            for (it = lesSommets->begin(); it != lesSommets->end(); ++it) {
                if (*sommet->getIdentifiant() == *it.operator*()->getIdentifiant()) {
                    lesSommets->erase(it);
                    if (lesSommets->empty())
                        lesSommets = NULL;
                    return true;
                }
            }
        }
    }
    return false;
}

template <class I, class P>
bool Graphe<I, P>::ajouterArete(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids) {
    if (src && dst && poids) {
        std::string *tmp = dst->getIdentifiant();
        bool x = src->ajouterVoisin(tmp, poids);
        tmp = src->getIdentifiant();
        return x && dst->ajouterVoisin(tmp, poids);
        /*bool y;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (x) {
            y = dst->ajouterVoisin(tmp, poids);
            delete tmp;
            return y;
        }
        return false;*/
    }
    return false;
}

template <class I, class P>
bool Graphe<I, P>::ajouterAreteOriente(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids) {
    if (src && dst && poids) {
        std::string *tmp = dst->getIdentifiant();
        return src->ajouterVoisin(tmp, poids);
        /*bool x;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        x = dst->ajouterVoisin(tmp, poids);
        delete tmp;
        return x;
        return false;*/
    }
    return false;
}


template <class I, class P>
bool Graphe<I, P>::supprimerArete(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids) {
    if (src && dst && poids) {
        std::string *tmp = dst->getIdentifiant();
        bool x = src->supprimerVoisin(tmp, poids);
        tmp = src->getIdentifiant();
        return x && dst->supprimerVoisin(tmp, poids);
        /*bool y;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if (x) {
            y = dst->supprimerVoisin(tmp, poids);
            delete tmp;
            return y;
        }
        return false;*/
    }
    return false;
}

template <class I, class P>
bool Graphe<I, P>::supprimerAreteOriente(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids) {
    if (src && dst && poids) {
        std::string *tmp = dst->getIdentifiant();
        return src->supprimerVoisin(tmp, poids);
        /*bool x;/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        x = dst->supprimerVoisin(tmp, poids);
        delete tmp;
        return x;
        return false;*/
    }
    return false;
}

template <class I, class P>
void Graphe<I, P>::afficher() {
    if (lesSommets) {
        typename std::vector<Sommet<I, P> *>::iterator it;
        for (it = lesSommets->begin(); it != lesSommets->end(); ++it) {
            it.operator*()->afficher();
        }
    } else
        std::cout << "graphe vide" << std::endl;
}

/*template <class I, class A>
std::vector<Sommet<I, A>*>* Graphe<I, A>::parcoursLargueur(Sommet<I, A> *racine) {
    std::vector<Sommet<I, A>*>* f = new std::vector<Sommet<I, A>*>();
    std::vector<Sommet<I, A>*>* res = new std::vector<Sommet<I, A>*>();
    Sommet<I, A> *tmp;
    f->push_back(racine);
    res->push_back(racine);
    while (!f->empty()) {
        tmp = f->back();
        f->pop_back();
        typename std::vector<Couple<I, A>*>::iterator t;
        for (t = tmp->getListe()->getVoisins()->begin(); t != tmp->getListe()->getVoisins()->end() ; ++t) {
            typename std::vector<Sommet<I, A>*>::iterator it;
            bool b = false;
            for (it = res->begin(); it != res->end(); ++it) {
                if (it.operator*()->getIdentifiant() == t.operator*()->getSommet()) {
                    b = true;
                    break;
                }
            }
            if (!b) {
                f->insert(f->begin(), t.operator*()->getSommet());
                res->push_back(t.operator*()->getSommet());
            }
        }
    }
    return res;
}*/

template class Graphe<std::string, int>;
