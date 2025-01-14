#include <iostream>
#include "Strada.h"
#include "Intersectie.h"
#include "Grafic.h"
using namespace std;
int main() {
    // Creare vehicule
    Vehicul v1(1, 50.0, 1, 3); 
    Vehicul v2(2, 60.0, 2, 3);

    // Creare străzi
    Strada strada1(1);
    strada1.adaugaVehicul(v1);
    strada1.adaugaVehicul(v2);

    // Creare intersecții
    Intersectie intersectie1(1, true);

    // Creare grafic și adăugare străzi
    Grafic grafic;
    grafic.adaugaStrada(1, 2, 10.0);
    grafic.adaugaStrada(2, 3, 5.0);
    grafic.adaugaStrada(1, 3, 15.0);

    // Calculare cel mai scurt drum
    int start = 1;
    int destinatie = 3;
    double distanta = grafic.celMaiScurtDrum(start, destinatie);

    // Afișare rezultate
    cout << "Strada 1 vehicule:" << endl;
    strada1.afiseazaVehicule();

    cout << "Intersectia 1 semafor: " << (intersectie1.getSemafor() ? "Verde" : "Roșu") << endl;

    if (distanta < numeric_limits<double>::infinity()) {
        cout << "Cea mai scurta distanta de punctul de plecare " << start << " la destinatie " << destinatie << " este: " << distanta << " minute" << endl;
    }
    else {
        cout << "Nu exista drum de la nodul " << start << " la nodul " << destinatie << endl;
    }

    return 0;
}
