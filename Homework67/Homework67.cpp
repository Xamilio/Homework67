#include <iostream>
#include <fstream>

using namespace std;

//class Fraction {
//private:
//    int numerator;
//    int denominator;
//
//public:
//    Fraction() : numerator(0), denominator(1) 
//    {
//
//    }
//
//    Fraction(int num, int denom) : numerator(num), denominator(denom) 
//    {
//
//    }
//
//    void writeToFile(ofstream& outFile) const 
//    {
//        outFile.write(reinterpret_cast<const char*>(this), sizeof(Fraction));
//    }
//
//    void readFromFile(ifstream& inFile)
//    {
//        inFile.read(reinterpret_cast<char*>(this), sizeof(Fraction));
//    }
//
//    void print() const {
//        cout << numerator << "/" << denominator << endl;
//    }
//};
//
//int main() {
//    Fraction fractions[4] = {
//        Fraction(1, 2),
//        Fraction(3, 4),
//        Fraction(5, 6),
//        Fraction(7, 8)
//    };
//
//    ofstream outFile("fractions.bin", ios::binary);
//    for (int i = 0; i < 4; ++i)
//    {
//        fractions[i].writeToFile(outFile);
//    }
//    outFile.close();
//
//    Fraction fractionsFromFile[4];
//
//    ifstream inFile("fractions.bin", ios::binary);
//    for (int i = 0; i < 4; ++i)
//    {
//        fractionsFromFile[i].readFromFile(inFile);
//    }
//    inFile.close();
//
//    cout << "Fractions read from file:" << endl;
//    for (const Fraction& fraction : fractionsFromFile)
//    {
//        fraction.print();
//    }
//}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() : numerator(0), denominator(1) 
    {

    }
    Fraction(int num, int denom) : numerator(num), denominator(denom) 
    {

    }

    void writeToFile(ofstream& outFile) const 
    {
        outFile.write(reinterpret_cast<const char*>(this), sizeof(Fraction));
    }

    void readFromFile(ifstream& inFile) 
    {
        inFile.read(reinterpret_cast<char*>(this), sizeof(Fraction));
    }

    void print() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction fractions[4] = {
        Fraction(1, 2),
        Fraction(3, 4),
        Fraction(5, 6),
        Fraction(7, 8)
    };

    ofstream outFile("fractions.bin", ios::binary);
    for (const Fraction& fraction : fractions) 
    {
        fraction.writeToFile(outFile);
    }
    outFile.close();

    Fraction fractionFromFile;

    ifstream inFile("fractions.bin", ios::binary);
    inFile.seekg(-(streamoff)sizeof(Fraction), ios::end);
    fractionFromFile.readFromFile(inFile);
    inFile.close();

    cout << "Fraction read from file:" << endl;
    fractionFromFile.print();
}