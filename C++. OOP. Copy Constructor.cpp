#include <iostream>

using namespace std;

class Vagon {
public:
    int number;
    int totalSeats;
    int passengers;

    Vagon() : number(0), totalSeats(0), passengers(0) {}

    Vagon(int num, int seats, int pass) : number(num), totalSeats(seats), passengers(pass) {}

    void Show() {
        cout << "Vagon-number: " << number << endl;
        cout << "Total-seats: " << totalSeats << endl;
        cout << "Passengers: " << passengers << endl;
    }
};

class Train {
public:
    string model;
    int vagonCount;
    Vagon* vagons;

    Train() : model(""), vagonCount(0), vagons(nullptr) {}

    Train(string mod) : model(mod), vagonCount(0), vagons(nullptr) {}

    void AddVagon(Vagon newVagon) {
        Vagon* newVagons = new Vagon[vagonCount + 1];
        for (int i = 0; i < vagonCount; i++) {
            newVagons[i] = vagons[i];
        }
        newVagons[vagonCount] = newVagon;
        delete[] vagons;
        vagons = newVagons;
        vagonCount++;
    }

    void Show() {
        cout << "Train model: " << model << endl;
        cout << "Number vagons: " << vagonCount << endl;
        for (int i = 0; i < vagonCount; i++) {
            vagons[i].Show();
        }
    }

    Train& operator=(const Train& other) {
        if (this != &other) {
            model = other.model;
            vagonCount = other.vagonCount;
            delete[] vagons;
            vagons = new Vagon[vagonCount];
            for (int i = 0; i < vagonCount; i++) {
                vagons[i] = other.vagons[i];
            }
        }
    }
};

int main() {
    Train train(" VladBot:-)");
    train.AddVagon(Vagon(1, 50, 20));
    train.AddVagon(Vagon(2, 60, 30));

    train.Show();
}
