//
// Created by Bonjour on 03/12/2018.
//

#ifndef TP5_COUPLE_HPP
#define TP5_COUPLE_HPP

template <class I, class P>
class Couple {
    private:
        I *sommet;
        P *poids;
    public:
//        Couple():sommet(), poids() {}
        Couple(I *&_sommet, P *&_poids):sommet(_sommet), poids(_poids) {}
        Couple(Couple<I, P> *&couple):sommet(couple->sommet), poids(couple->poids) {}
        ~Couple();

        void afficher();
        I* getSommet() { return sommet; }
        P* getPoids() { return poids; }
};


#endif //TP5_COUPLE_HPP
