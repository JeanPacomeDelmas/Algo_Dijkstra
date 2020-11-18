/*questions:
 *  - pour les delete
 *  - delete == free?
 *  - histoire de reference*/


#include <iostream>
#include <cstdio>
#include "Graphe.hpp"

int main() {
    std::cout << "couple: ";
    std::string *nomSommetCouple = new std::string("a");
    int *poidsCouple = new int(3);
    Couple<std::string, int> *couple = new Couple<std::string, int>(nomSommetCouple, poidsCouple);
    couple->afficher();
    std::cout << std::endl;
    std::string *nomSommetCouple2 = new std::string("c");
    int *poidsCouple2 = new int(2);
    Couple<std::string, int> *couple2 = new Couple<std::string, int>(nomSommetCouple2, poidsCouple2);

    std::cout << "sommet: ";
    std::string *nomSommet = new std::string("b");
    Sommet<std::string, int> *sommet = new Sommet<std::string, int>(nomSommet);
    sommet->afficher();

    std::cout << "sommet apres ajout: ";
    sommet->ajouterVoisin(couple);
    std::string *tmpString2 = couple2->getSommet();
    int *tmpInt2 = couple2->getPoids();
    sommet->ajouterVoisin(tmpString2, tmpInt2);
    sommet->afficher();
    sommet->supprimerVoisin(couple);
    sommet->afficher();
    sommet->supprimerVoisin(couple2);
    sommet->afficher();



    std::string *nomSommet2 = new std::string("d");
    Sommet<std::string, int> *sommet2 = new Sommet<std::string, int>(nomSommet2);
    Graphe<std::string, int> *graphe = new Graphe<std::string, int>;
    graphe->afficher();
    graphe->ajouterSommet(sommet);
    graphe->ajouterSommet(sommet2);
    graphe->afficher();
    int *poids = new int(6);
    graphe->ajouterArete(sommet, sommet2, poids);
    graphe->afficher();
    graphe->supprimerArete(sommet, sommet2, poids);
    graphe->afficher();
    graphe->supprimerSommet(sommet2);
    graphe->afficher();





    delete sommet;
//    std::cout << "del s" << std::endl;
    delete couple;
//    std::cout << "del cpl" << std::endl;
//    delete coupleTest;
//    std::cout << "del cpltest" << std::endl;
//    delete nomSommet;
//    std::cout << "del nom sommet" << std::endl;
//    delete nomSommetCouple;
//    std::cout << "del nomstest" << std::endl;
//    delete poidsCouple;
    std::cout << "fin" << std::endl


    return 0;
}