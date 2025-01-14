#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
#include <functional> 
using namespace std;
class Grafic {
public:
    void adaugaStrada(int nod1, int nod2, double distanta) {
        grafic[nod1].emplace_back(nod2, distanta);
        grafic[nod2].emplace_back(nod1, distanta); // dacă străzile sunt bidirecționale
    }

    double celMaiScurtDrum(int start, int destinatie) {
        unordered_map<int, double> distanta;
        unordered_map<int, bool> vizitat;

        for (const auto& nod : grafic) {
            distanta[nod.first] = numeric_limits<double>::infinity();
            vizitat[nod.first] = false;
        }
        distanta[start] = 0;

        using PDI = pair<double, int>;
        priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            PDI top = pq.top();
            double d_curenta = top.first;
            int nod_curent = top.second;
            pq.pop();

            if (vizitat[nod_curent]) continue;
            vizitat[nod_curent] = true;

            if (nod_curent == destinatie) {
                return d_curenta;
            }

            for (const auto& vecin_pair : grafic[nod_curent]) {
                int vecin = vecin_pair.first;
                double greutate = vecin_pair.second;
                double d_noua = d_curenta + greutate;
                if (d_noua < distanta[vecin]) {
                    distanta[vecin] = d_noua;
                    pq.push(make_pair(d_noua, vecin));
                }
            }
        }
        return numeric_limits<double>::infinity(); // dacă nu există drum
    }

private:
    unordered_map<int, vector<pair<int, double>>> grafic;
};
