
class Vehicul {
public:
    Vehicul(int id, double viteza, int start, int destinatie)
        : id(id), viteza(viteza), pozitie(start), start(start), destinatie(destinatie) {}

    int getId() const { return id; }
    double getViteza() const { return viteza; }
    void setViteza(double vitezaNoua) { viteza = vitezaNoua; }

    int getPozitie() const { return pozitie; }
    void setPozitie(int pozitieNoua) { pozitie = pozitieNoua; }

    int getStart() const { return start; }
    int getDestinatie() const { return destinatie; }

private:
    int id;
    double viteza;
    int pozitie;
    int start;
    int destinatie;
};

    


