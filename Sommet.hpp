//
// Created by Bonjour on 03/12/2018.
//

#ifndef TP5_SOMMET_HPP
#define TP5_SOMMET_HPP

#include <string>
#include <vector>
#include "Couple.hpp"

template <class I, class P>
class Sommet {
    friend class Couple<I, P>;
    private:
        I *identifiant;
        std::vector<Couple<I, P>*> *lesVoisins;
    public:
//        Sommet():identifiant(), lesVoisins() {}
        Sommet(I *&_identifiant):identifiant(_identifiant), lesVoisins() {}
        Sommet(Sommet<I, P> *&sommet):identifiant(sommet->identifiant), lesVoisins() {}
        ~Sommet();

        Couple<I, P>* rechercherVoisins(I *nomSommet, P *poids);
        bool ajouterVoisin(I *&nomSommet, P *&poids);
        bool ajouterVoisin(Couple<I, P> *&couple);
        bool supprimerVoisin(I *&nomSommet, P *&poids);
        bool supprimerVoisin(Couple<I, P> *&couple);
        void afficher();

        I* getIdentifiant() const { return identifiant; }
        std::vector<Couple<I, P>*>* getLesVoisins() const { return lesVoisins; }
};


#endif //TP5_SOMMET_HPP
