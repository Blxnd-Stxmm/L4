#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;
class Pair
{
public:
    virtual void Ciing() = 0;
    virtual void couting() = 0;
};
class FazzyNumber : public Pair
{
private:
    double A, A1, A2;
public:
    void Ciing() override
    {
        cin >> A >> A1 >> A2;
    }
    void couting() override
    {
        cout << '(' << A1 << ',' << A << ',' << A2 << ')';
    }
    void CoutingTheNumberItself()
    {
        cout << '(' << A - A1 << ',' << A << ',' << A + A2 << ')';
    }
    friend FazzyNumber operator+(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2)
    {
        FazzyNumber FazzySum;
        FazzySum.A = Fuzzy1.A + Fuzzy2.A;
        FazzySum.A1 = Fuzzy1.A + Fuzzy2.A - Fuzzy1.A1 - Fuzzy2.A1;
        FazzySum.A2 = Fuzzy1.A + Fuzzy2.A + Fuzzy1.A2 + Fuzzy2.A2;
        return FazzySum;
    }
    friend FazzyNumber operator-(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2)
    {
        FazzyNumber FazzyDif;
        FazzyDif.A = Fuzzy1.A - Fuzzy2.A;
        FazzyDif.A1 = Fuzzy1.A - Fuzzy2.A - Fuzzy1.A1 - Fuzzy2.A1;
        FazzyDif.A2 = Fuzzy1.A - Fuzzy2.A + Fuzzy1.A2 + Fuzzy2.A2;
        return FazzyDif;
    }
    friend FazzyNumber operator*(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2)
    {
        FazzyNumber FazzyMul;
        FazzyMul.A = Fuzzy1.A * Fuzzy2.A;
        FazzyMul.A1 = Fuzzy1.A * Fuzzy2.A - Fuzzy1.A1 * Fuzzy2.A - Fuzzy1.A * Fuzzy2.A1 + Fuzzy1.A1 * Fuzzy2.A1;
        FazzyMul.A2 = Fuzzy1.A * Fuzzy2.A + Fuzzy1.A1 * Fuzzy2.A + Fuzzy1.A * Fuzzy2.A2 + Fuzzy1.A2 * Fuzzy2.A2;
        return FazzyMul;
    }
    friend FazzyNumber operator/(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2)
    {
        FazzyNumber FazzyDiv;
        FazzyDiv.A1 = (Fuzzy1.A - Fuzzy1.A1) / (Fuzzy2.A + Fuzzy2.A2);
        FazzyDiv.A = Fuzzy1.A / Fuzzy2.A;
        FazzyDiv.A2 = (Fuzzy1.A + Fuzzy1.A1) / (Fuzzy2.A - Fuzzy2.A1);
        return FazzyDiv;
    }
};
class Complex : public Pair
{
private:
    double A, B;
public:
    void Ciing() override
    {
        cin >> A >> B;
    }
    void couting() override
    {
        cout << '(' << A << "+i*" << B << ')';
    }
    friend Complex operator+(Complex Complex1, Complex Complex2)
    {
        Complex ComplexSum;
        ComplexSum.A = Complex1.A + Complex2.A;
        ComplexSum.B = Complex1.B + Complex2.B;
        return ComplexSum;
    }
    friend Complex operator-(Complex Complex1, Complex Complex2)
    {
        Complex ComplexDif;
        ComplexDif.A = Complex1.A - Complex2.A;
        ComplexDif.B = Complex1.B - Complex2.B;
        return ComplexDif;
    }
    friend Complex operator*(Complex Complex1, Complex Complex2)
    {
        Complex ComplexMul;
        ComplexMul.A = Complex1.A * Complex2.A - Complex1.B * Complex2.B;
        ComplexMul.B = Complex1.A * Complex2.B + Complex1.B * Complex2.A;
        return ComplexMul;
    }
    friend Complex operator/(Complex Complex1, Complex Complex2)
    {
        Complex ComplexMul;
        ComplexMul.A = (Complex1.A * Complex2.A + Complex1.B * Complex2.B) / (pow(Complex2.A, 2) + pow(Complex2.B, 2));
        ComplexMul.B = (Complex1.B * Complex2.A - Complex1.A * Complex2.B) / (pow(Complex2.A, 2) + pow(Complex2.B, 2));
        return ComplexMul;
    }
};
void CoutingFazzy(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2);
void CoutingComplex(Complex Complex1, Complex Complex2);
void menu(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2, Complex Complex1, Complex Complex2)
{
    int chosenOption = 0;
    cin >> chosenOption;
    switch (chosenOption)
    {
    case 1:
    {
        Fuzzy1.Ciing();
        CoutingFazzy(Fuzzy1, Fuzzy2);
        menu(Fuzzy1, Fuzzy2, Complex1, Complex2);
        break;
    }
    case 2:
    {
        Fuzzy2.Ciing();
        CoutingFazzy(Fuzzy1, Fuzzy2);
        menu(Fuzzy1, Fuzzy2, Complex1, Complex2);
        break;
    }
    case 3:
    {
        Complex1.Ciing();
        CoutingComplex(Complex1, Complex2);
        menu(Fuzzy1, Fuzzy2, Complex1, Complex2);
        break;
    }
    case 4:
    {
        Complex2.Ciing();
        CoutingComplex(Complex1, Complex2);
        menu(Fuzzy1, Fuzzy2, Complex1, Complex2);
        break;
    }
    case 0:
    {
        break;
    }
    }
}
void CoutingFazzy(FazzyNumber Fuzzy1, FazzyNumber Fuzzy2)
{
    cout << "FazzyNumber1 ";
    Fuzzy1.CoutingTheNumberItself();
    cout << " FazzyNumber2 ";
    Fuzzy2.CoutingTheNumberItself();
    FazzyNumber FazzySum = Fuzzy1 + Fuzzy2;
    cout << endl << "FazzyNumber1+FazzyNumber2 ";
    FazzySum.couting();
    cout << endl << "FazzyNumber1-FazzyNumber2 ";
    FazzyNumber FazzyDif = Fuzzy1 - Fuzzy2;
    FazzyDif.couting();
    cout << endl << "FazzyNumber1*FazzyNumber2 ";
    FazzyNumber FazzyMul = Fuzzy1 * Fuzzy2;
    FazzyMul.couting();
    cout << endl << "FazzyNumber1/FazzyNumber2 ";
    FazzyNumber FazzyDiv = Fuzzy1 / Fuzzy2;
    FazzyDiv.couting();
    cout << endl;
    return;
}
void CoutingComplex(Complex Complex1, Complex Complex2)
{
    cout << "Complex1 ";
    Complex1.couting();
    cout << " Complex2 ";
    Complex2.couting();
    Complex ComplexSum = Complex1 + Complex2;
    cout << endl << "Complex1+Complex2 ";
    ComplexSum.couting();
    Complex ComplexDif = Complex1 - Complex2;
    cout << endl << "Complex1-Complex2 ";
    ComplexDif.couting();
    Complex ComplexMul = Complex1 * Complex2;
    cout << endl << "Complex1*Complex2 ";
    ComplexMul.couting();
    Complex ComplexDiv = Complex1 / Complex2;
    cout << endl << "Complex1/Complex2 ";
    ComplexDiv.couting();
    cout << endl;
    return;
}
void main()
{
    FazzyNumber Fuzzy1, Fuzzy2;
    Fuzzy1.Ciing();
    Fuzzy2.Ciing();
    Complex Complex1, Complex2;
    Complex1.Ciing();
    Complex2.Ciing();
    CoutingFazzy(Fuzzy1, Fuzzy2);
    CoutingComplex(Complex1, Complex2);
    menu(Fuzzy1, Fuzzy2, Complex1, Complex2);
    //return 0;
}