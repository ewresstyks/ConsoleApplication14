// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 
using namespace std;

class Flat {
    int flatss;
    char* adr;
    double price;
public:
    Flat() {
        price = 0;
        adr = nullptr;
        flatss = 0;
    }
    Flat(const char* _adr, int _flatss, double _price) {
        flatss = _flatss;
        price = _price;
        adr = new char[strlen(_adr) + 1];
        strcpy_s(adr, strlen(_adr) + 1, _adr);
    }

    ~Flat() {
        delete[] adr;
        cout << "Dest";
    }

    Flat(const Flat& obj) {
        flatss = obj.flatss;
        price = obj.price;
        adr = new char[strlen(obj.adr) + 1];
        strcpy_s(adr, strlen(obj.adr) + 1, obj.adr);
    }

    Flat& operator=(const Flat& obj)
    {
        if (this == &obj) {
            return *this;
        }
        if (adr != nullptr) {
            delete[]adr;
        }
        flatss = obj.flatss;
        price = obj.price;
        adr = new char[strlen(obj.adr) + 1];
        strcpy_s(adr, strlen(obj.adr) + 1, obj.adr);
        return *this;
    }

    bool operator==(const Flat& obj)
    {
        if (flatss == obj.flatss) {
            return true;
        }
        return false;
    }

    bool operator>(const Flat& obj)
    {
        if (price > obj.price) {
            return true;
        }
        return false;
    }

    void Print() {
        cout << adr << endl << price << endl << flatss << endl;
    }
};

int main() {
    Flat a("first flat", 23, 129990);
    Flat b("2 flat", 35, 18900);
    Flat c = a;
    Flat d("3 flat", 19, 119800);
    d = b;
    if (a == c) cout << "a and c have the same area" << endl;
    if (b > a) cout << "b is more expensive than a" << endl;
    a.Print();
}