#ifndef PEA_PROJEKT_GENETYCZNY
#define PEA_PROJEKT_GENETYCZNY
#include "matrix.h"

class geneticAlgorithm{
    private:
        int *best_path;
        int timeBound;
        int **mesh;
        int size, populationSize, stop;
        float crossRate, mutationRate;
        //sprawdzanie czy podany wezel znajduje sie juz w sciezce
        bool isIn(int *path, int start, int end, int value);
        //kopiowanie wartosci z tablicy do drugiej tablicy
        void copyTab(int *tab1, int *tab2);
        //zwraca losowa permutacje
        int *random_permutation();
        //oblicza dlugosc podanej sciezki
        int calculatePath(int *path);
        //krzyzowanie OX
        void orderCrossover(int *parent1, int *parent2);
        //krzyzowanie PMX
        void partiallyCrossover(int *parent1, int *parent2);
    public:
        //konstruktor glowny
        geneticAlgorithm(Matrix matrix,int population, float crossRate, float mutationRate, int time);
        //metoda zaczynajaca algorytm, zwracajaca najlepsze rozwiazanie
        int start(int choose);
        //pusty konstruktor 
        geneticAlgorithm();
        //zwracanie najlepszej sciezki
        void best_result();
      

        
        
        
};


#endif