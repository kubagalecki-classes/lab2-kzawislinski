#include <iostream>

struct Wektor
{
public:
    Wektor(int n) : dlugosc{n}, pojemnosc{n}, v1{new double[n]}
    {
        for (int i = 0; i < n; i++) {
            v1[i] = 0;
        };
    }

    Wektor(const Wektor& kopia)
        : dlugosc{kopia.dlugosc}, pojemnosc{kopia.pojemnosc}, v1{new double[kopia.pojemnosc]}
    {
        for (int i = 0; i < dlugosc; i++) {
            v1[i] = kopia.v1[i];
        };
    };

    ~Wektor() { delete[] v1; }

    int  getD() { return dlugosc; }
    int  getP() { return pojemnosc; }
    void zmienDlugosc(int a)
    {
        if (a <= pojemnosc) {
            dlugosc = a;
            for (int i = dlugosc; i < pojemnosc; i++)
                v1[i] = 0;
        }
        else {
            double* temp = new double[dlugosc];
            for (int i = 0; i < dlugosc; i++) {
                temp[i] = v1[i];
            }
            delete[] v1;
            v1 = new double[a];
            for (int i = 0; i < dlugosc; i++) {
                v1[i] = temp[i];
            }
            delete[] temp;
            for (int i = dlugosc; i < a; i++) {
                v1[i] = 0;
            }
            dlugosc   = a;
            pojemnosc = a;
        }
    }

    void print()
    {
        for (int i = 0; i < dlugosc; i++) {
            std::cout << "v1[" << i << "] = " << v1[i] << '\n';
        };
    }
    double& operator[](int n)
    {
        if (n >= pojemnosc) {
            zmienDlugosc(n + 1);
        }
        return v1[n];
    };

    Wektor& operator=(Wektor& v2)
    {
        delete[] v1;
        v1 = new double(v2.getD());
        for (int i = 0; i < v2.getD(); i++) {
            v1[i] = v2[i];
        }
        dlugosc   = v2.getD();
        pojemnosc = v2.getD();
        return *this;
    }

private:
    int     dlugosc;
    int     pojemnosc;
    double* v1;
};

int main()
{
    int x;
    std::cout << "Podaj rozmiar wektora \n";
    std::cin >> x;
    Wektor w1(x);
    std::cout << "Dlugosc wektora: " << w1.getD() << "\nPojemnosc wektora: " << w1.getP() << '\n';
    for (int i = 0; i < w1.getD(); i++) {
        w1[i] = i + 1;
    }
    w1.print();
    std::cout << "Dlugosc wektora: " << w1.getD() << "\nPojemnosc wektora: " << w1.getP() << '\n';
    std::cout << "Podaj nowy rozmiar wektora \n";
    std::cin >> x;
    w1.zmienDlugosc(x);
    for (int i = 0; i < w1.getD(); i++) {
        w1[i] = w1.getD() - i;
    }
    w1.print();
    std::cout << "Dlugosc wektora: " << w1.getD() << "\nPojemnosc wektora: " << w1.getP() << '\n';
    std::cout << w1[w1.getP() + 3] << '\n';
    std::cout << "Dlugosc wektora: " << w1.getD() << "\nPojemnosc wektora: " << w1.getP() << '\n';
    Wektor w2{w1};
    std::cout << "wektor 2 powstaly na podstawie wektora 1: \n";
    w2.print();
    std::cout << "Dlugosc wektora: " << w2.getD() << "\nPojemnosc wektora: " << w2.getP() << '\n';
    w2.zmienDlugosc(3);
    std::cout << "wektor 2 skrocony: \n";
    w2.print();
    std::cout << "Dlugosc wektora: " << w2.getD() << "\nPojemnosc wektora: " << w2.getP() << '\n';
    w1 = w2;
    std::cout << "wektor 1 skopiowany z wektora 2: \n";
    w1.print();
    std::cout << "Dlugosc wektora: " << w1.getD() << "\nPojemnosc wektora: " << w1.getP() << '\n';
}
