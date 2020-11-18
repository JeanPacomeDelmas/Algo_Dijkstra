//
// Created by Bonjour on 03/12/2018.
//

#ifndef TP5_GRAPHE_HPP
#define TP5_GRAPHE_HPP

#include <vector>
#include "Sommet.hpp"

template <class I, class P>
class Graphe {
    private:
        std::vector<Sommet<I, P>*> *lesSommets;
    public:
        Graphe():lesSommets() {}
        ~Graphe();

        Sommet<I, P>* rechercher(Sommet<I, P> *sommet);
        bool ajouterSommet(Sommet<I, P> *&sommet);
        bool ajouterArete(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids);
//        bool ajouterArete(Couple<I, P> *&srcToDst, Couple<I, P> *&dstToSrc, P *&poids);
        bool ajouterAreteOriente(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids);
        bool supprimerSommet(Sommet<I, P> *&sommet);
        bool supprimerArete(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids);
        bool supprimerAreteOriente(Sommet<I, P> *&src, Sommet<I, P> *&dst, P *&poids);
        void afficher();

        std::vector<Sommet<I, P>*>* getLesSommets() { return lesSommets; };
};


#endif //TP5_GRAPHE_HPP
