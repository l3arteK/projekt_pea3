#ifndef PROJEKT_PEA_MATRIX
#define PROJEKT_PEA_MATRIX
#include <iostream>
 class Matrix
{
    int size = 0;
    int **tank = nullptr;

public:
    Matrix();
    //tworzenie dwuwymiarowej tablicy o podanym rozmiarze
    Matrix(int x);
    //pobieranie wartosci o podanych koordynatach
    int get(int x, int y);
    //pobranie wielkosci macierzy
    int getSize();
    //wyswietlenie zawartosci macierzy
    void show();
    //modyfikacja konkretnej komórki w macierzy
    void modyfiy_value(int x, int y, int value);
    //generowanie randomowych danych w macierzy
    void generate_data();
    //zwracanie dwuwymiarowej tablicy
    int ** getMatrix();
    //wczytywanie pliku atsp
    bool readFromFile(std::string fileName);
    //wczytywanie z pliku txt
    bool readFromFile2(std::string fileName);
};





#endif