#include "matrix.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Matrix::Matrix(){
}

//tworzenie dwuwymiarowej tablicy o podanym rozmiarze
 Matrix::Matrix(int x){
    this->size = x;
    tank = new int *[x];
    for (int i = 0 ;i<x;i++){
        tank[i] = new int[x];
    }
}
//pobieranie wartosci i podanych koordynatach
int Matrix::get(int x, int y){
    return tank[x][y];
}
//wyswietlenie zawartosci macierzy
void Matrix::show(){
    for(int i = 0;i<size;i++){
        for(int j = 0; j<size;j++)
            std::cout<<tank[i][j]<<" ";
        std::cout<<std::endl;
    }
}
//modyfikacja konkretnej komórki w macierzy
void Matrix::modyfiy_value(int x, int y, int value){
    tank[x][y] = value;
}
//pobranie wielkosci macierzy
int Matrix::getSize(){
    return size;
}
//generowanie randomowych danych w macierzy
void Matrix::generate_data(){
    for(int i = 0;i<size;i++)
        for(int j = 0; j<size;j++)
            modyfiy_value(i,j,rand()%100 +1);
}
//zwracanie dwuwymiarowej tablicy
int ** Matrix::getMatrix(){
    return tank;
}
//wczytywanie pliku atsp
bool Matrix::readFromFile(std::string fileName){
    int **temp;
    int pom;
    string str;
    ifstream file;
    file.open(fileName);

    if(file.fail() || file.eof())
        return false;
    
    if(size!=0){
        for(int i = 0; i<size;i++)
            delete [] tank[i];
        delete[] tank;
    }

    getline(file,str);
    getline(file,str);
    getline(file,str);
    file>>str;
    file>>size;
    getline(file, str);
    getline(file,str);
    getline(file,str);
    getline(file,str);
    temp = new int*[size];
    for(int i = 0;i<size;i++)
        temp[i] = new int[size];
    
    for(int i = 0; i<size;i++){
        for(int j = 0; j<size;j++){
            file>>temp[i][j];
        }
    }
            
    
    file.close();
    tank = temp;
    return true;
}
//wczytywanie z pliku txt
bool Matrix::readFromFile2(std::string fileName){
    int **temp;

    ifstream file;
    file.open(fileName);
    
    if(file.fail() || file.eof())
        return false;
    
    if(size!=0){
        for(int i = 0; i<size;i++)
            delete [] tank[i];
        delete[] tank;
    }

    file>>size;
    temp = new int*[size];
    for(int i = 0;i<size;i++)
        temp[i] = new int[size];
    
    for(int i = 0; i<size;i++){
        for(int j = 0; j<size;j++){
            file>>temp[i][j];
        }
    }
    file.close();
    tank = temp;
    return true;
}
