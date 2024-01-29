#ifndef PEA_PROJEKT_GENETYCZNY
#define PEA_PROJEKT_GENETYCZNY
#include "matrix.h"

class geneticAlgorithm{
    private:
        int timeBound;
        int **mesh;
        int size, populationSize, stop;
        float crossRate, mutationRate;
        bool isIn(int *path, int start, int end, int value);
        void copyTab(int *tab1, int *tab2);
        int *random_permutation();
    
        int calculatePath(int *path);
        void orderCrossover(int *parent1, int *parent2);
        void partiallyCrossover(int *parent1, int *parent2);
    public:

        geneticAlgorithm(Matrix matrix,int population, float crossRate, float mutationRate, int time);
        int start(int choose);
      

        
        
        
};


#endif