#include <iostream>

using namespace std;

class LiczbZespolona {
private:
    double re;
    double im;

public:
    LiczbZespolona() {
        re = 0;
        im = 0;
    }

    LiczbZespolona(double r, double i) {
        re = r;
        im = i;
    }

    LiczbZespolona(const LiczbZespolona& inna) {
        re = inna.re;
        im = inna.im;
    }

    ~LiczbZespolona() {
    }

    LiczbZespolona& operator=(const LiczbZespolona& inna) {
        re = inna.re;
        im = inna.im;
        return *this;
    }

    LiczbZespolona operator+(const LiczbZespolona& inna) {
        LiczbZespolona wynik;
        wynik.re = re + inna.re;
        wynik.im = im + inna.im;
        return wynik;
    }

    LiczbZespolona operator-(const LiczbZespolona& inna) {
        return LiczbZespolona(re - inna.re, im - inna.im);
    }

    LiczbZespolona operator*(const LiczbZespolona& inna) {
        double nowe_re = re * inna.re - im * inna.im;
        double nowe_im = re * inna.im + im * inna.re;
        return LiczbZespolona(nowe_re, nowe_im);
    }

    LiczbZespolona operator/(const LiczbZespolona& inna) {
        double mianownik = inna.re * inna.re + inna.im * inna.im;
        double nowe_re = (re * inna.re + im * inna.im) / mianownik;
        double nowe_im = (im * inna.re - re * inna.im) / mianownik;

        return LiczbZespolona(nowe_re, nowe_im);
    }

    double getRe() { return re; }
    double getIm() { return im; }

    friend ostream& operator<<(ostream& os, const LiczbZespolona& lz) {
        os << lz.re << " + " << lz.im << "i";
        return os;
    }
};

int main() {
    LiczbZespolona z1;
    LiczbZespolona z2(3.0, 4.0);
    LiczbZespolona z3(z2);

    LiczbZespolona z4(5.0, 2.0);
    LiczbZespolona z5(1.0, 3.0);

    LiczbZespolona suma = z4 + z5;
    LiczbZespolona roznica = z4 - z5;
    LiczbZespolona iloczyn = z4 * z5;
    LiczbZespolona iloraz = z4 / z5;

    cout << "Suma: " << suma << endl;
    cout << "Roznica: " << roznica << endl;
    cout << "Iloczyn: " << iloczyn << endl;
    cout << "Iloraz: " << iloraz << endl;

    return 0;
}