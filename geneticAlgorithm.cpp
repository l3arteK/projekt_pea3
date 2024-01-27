#include "geneticAlgorithm.h"

#include <ctime>


geneticAlgorithm::geneticAlgorithm(Matrix matrix,int population, float crossRate, float mutationRate, int time ){
    timeBound = time;
    mesh = matrix.getMatrix();
    size = matrix.getSize();
    this->populationSize = population;
    this->crossRate = crossRate;
    this->mutationRate = mutationRate;
}
int geneticAlgorithm::calculatePath(int *path){
    int result = 0;
    for(int i = 0;i<size-1;i++){
       result+= mesh[path[i]][path[i+1]];
    }
    result+=mesh[path[size-1]][path[0]];
    return result;
}

void geneticAlgorithm::partiallyCrossover(int *parent1, int *parent2){
    int *child1, *child2, *map1, *map2;
    int crossStart, crossEnd, temp;
    child1 = new int[size];
    child2 = new int[size];
    map1 = new int[size];
    map2 = new int[size];

    for(int i = 0 ;i<size;i++){
        child1[i] = -1;
        child2[i] = -1;
    }

    do {
        crossStart = (rand() % size-2) +1;
        crossEnd = (rand() % size-2) + 1;
    } while (0 >= (crossStart - crossEnd));


    for(int i = crossStart; i<=crossEnd; i++){
        child1[i] = parent1[i];
        child2[i] = parent2[i];
        map1[parent1[i]] = parent2[i];
        map2[parent2[i]] = parent1[i];
    }

    for(int i = 0; i < size; i++){
        if(child1[i] == -1){
            if(!isIn(child2, crossStart, crossEnd, parent1[i])){
                child2[i] = parent1[i];
            }
            else{
                temp = parent1[i];
                do{
                    temp = map1[temp];
                }while(isIn(child2, crossStart, crossEnd, temp));
            }
            
            child2[i] = temp;
        }
        if(child2[i] == -1){
            if(!isIn(child1, crossStart, crossEnd, parent2[i])){
                child1[i] = parent2[i];
            }
            else{
                temp = parent2[i];
                do{
                    temp = map1[temp];
                }while(isIn(child1, crossStart, crossEnd, temp));
            }
            
            child1[i] = temp;
        }
    }

    parent1 = child1;
    parent2 = child2;

}
void geneticAlgorithm::orderCrossover(int *parent1, int* parent2){
    int *child1, *child2;
    child1 = new int[size];
    child2 = new int[size];
    int crossStart, crossEnd, temp;
    int x1,y1,x2,y2;

    do {
        crossStart = (rand() % size-2) +1;
        crossEnd = (rand() % size-2) + 1;
    } while (0 >= (crossStart - crossEnd));

    for(int i = crossStart; i<=crossEnd; i++){
        child1[i] = parent1[i];
        child2[i] = parent2[i];
    }

    x1 = crossEnd+1;
    y1 = crossEnd+1;
    x2 = crossEnd+1;
    y2 = crossEnd+1;

    while(x2!=crossStart){
        if(x1==size)
            x1%=size;
        if(!(isIn(child1,crossStart, crossEnd,parent2[y1]))){
            child1[x1] = parent2[y1];
            x1++;
            y1++;
        }
        else{
            do{
                y1++;
                y1%=size;
            }while(isIn(child1, crossStart, crossEnd, parent2[y1]));

            child1[x1] = parent2[y1];
            x1++;
        }

        if(x2 == size)
            x2%=size;
        if(!(isIn(child1,crossStart, crossEnd,parent1[y2]))){
            child2[x2] = parent1[y2];
            x2++;
            y2++;
        }
        else{
            do{
                y2++;
                y2%=size;
            }while(isIn(child1, crossStart, crossEnd, parent2[y1]));

            child1[x2] = parent2[y2];
            x2++;
        }
    }

    parent1 = child1;
    parent2 = child2;

}

bool geneticAlgorithm::isIn(int *path, int start, int end, int value){
    for (int i = start; i <= end; i++) {
        if (value == path[i])
            return true;
    }
    return false;
}
int geneticAlgorithm::start(int choose){
    int **population, **nxtPopulation;
    int *fitness, *permutation;
    int tournamentSize = 5;
    clock_t start;
    int best, number, p1, p2;
    int result = INT_MAX;
    fitness = new int[populationSize];
    population = new int*[populationSize];
    nxtPopulation = new int*[populationSize];

    for(int i = 0 ; i<populationSize; i++){
        population[i] = random_permutation();
        nxtPopulation[i] = new int[size];
    }
    
    start = clock();

    while((clock() - start)/ (CLOCKS_PER_SEC) < timeBound){
        for(int i = 0;i<populationSize;i++){
            fitness[i] = calculatePath(population[i]);
        }

        for(int i =0; i <populationSize; i++){
            best = INT_MAX;

            for(int j = 0; j<tournamentSize; j++){
                number = rand() % populationSize;

                if(fitness[number] < best){
                    best = fitness[number];
                    permutation = population[number];
                }

            }
            copyTab(nxtPopulation[i],permutation);
        }

     for(int i = 0; i<populationSize; i++){
        copyTab(population[i],nxtPopulation[i]);
     }

    for(int i = 0; i <(int)(crossRate * (float)populationSize);i+=2){
        do {
            p1 = rand() % populationSize;
            p2 = rand() % populationSize;
        } while (p1==p2);

        if(choose == 0)
            orderCrossover(population[p1], population[p2]);
        else
            partiallyCrossover(population[p1], population[p2]);
    }

    for(int i = 0; i<(int)(mutationRate*(float)populationSize);i++){
        do {
            p1 = rand() % size;
            p2 = rand() % size;
        } while (p1==p2);

        int temp = population[i][p1];
        population[i][p1] = population[i][p2];
        population[i][p2] = temp;

    }
 
    }

    for(int i = 0; i < populationSize; i++){
        if(fitness[i] < result)
        result = fitness[i];
    }

    return result;
}
void geneticAlgorithm::copyTab(int *tab1, int*tab2){
    for(int i  = 0;i<size;i++){
        tab1[i] = tab2[i];
    }
}
int * geneticAlgorithm::random_permutation(){
    int *tab = new int[size];
    bool repeat=false;
    for(int i=0;i<size;i++){
        tab[i] = rand()%size;
        for(int j=0;j<i;j++){
            if(tab[i] == tab[j] && j!=i){
                repeat = true;
                break;
            }
        }
        if(repeat){
            i--;
            repeat = false;
        }
    }
    return tab;
}