
class Intersectie {
public:
    Intersectie(int id, bool semafor) : id(id), semafor(semafor) {}

    int getId() const { return id; }
    bool getSemafor() const { return semafor; }
    void setSemafor(bool stare) { semafor = stare; }

private:
    int id;
    bool semafor;
};

