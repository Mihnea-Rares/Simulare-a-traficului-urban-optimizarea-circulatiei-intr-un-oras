#include <vector>
#include "Vehicul.h"
#include <iostream>
using namespace std;

class Strada {
public:
    Strada(int id) : id(id) {}

    int getId() const { return id; }
    void adaugaVehicul(const Vehicul& vehicul) { vehicule.push_back(vehicul); }
    void afiseazaVehicule() const {
        for (const auto& vehicul : vehicule) {
            cout << "Vehicul ID: " << vehicul.getId()
                << ", Viteza: " << vehicul.getViteza()
                << ", Pozitie: " << vehicul.getPozitie()
                << ", Punct de Plecare: " << vehicul.getStart()
                << ", Destinatie: " << vehicul.getDestinatie() << endl;
        }
    }

private:
    int id;
    vector<Vehicul> vehicule;
};
