#ifndef PEA_PROJEKT_GENETYCZNY
#define PEA_PROJEKT_GENETYCZNY
#include "matrix.h"

class geneticAlgorithm{
    private:
        int **mesh;
        int size, populationSize, stop;
        float crossRate, mutationRate;


    public:

        geneticAlgorithm(Matrix matrix,int population, float crossRate, float mutationRate);
        int calculatePath(int **tab);
        void orderCrossover(int *parent1, int *parent2);
        void partiallyCrossover(int *parent1, int * parent2);
        
};


#endif