#include <iostream>
#include "geneticAlgorithm.h"
#include <fstream>
#include <conio.h>
using namespace std;
void menu(){
    cout << "\n\n";
    cout<<"==============================\n";
    cout<< "1. Load file"<<endl;
    cout << "2. Start algorithm "<<endl;
    cout << "0. Back"<<endl;
    cout<<"==============================\n";
	cout << "Enter number: ";
}

int main(){
    char option;
    Matrix matrix;
    string fileName="";
    int max_time, pop_size;
    float crossRate, mutationRate;
    bool wczytany = false;
    srand(time(NULL));
    do{
        cout<<"Actually loaded file: "<<fileName<<endl;
        menu();
        option = _getche();

        switch(option){
            case '1':
                cout<<"\nType of file: "<<endl;
                cout<<"1. .atsp"<<endl;
                cout<<"2. .txt"<<endl;
                option = _getche();
                do{
                cout<<"\nEnter filename: ";
                cin>>fileName;
                    if(option == '1'){
                        if(matrix.readFromFile(fileName))
                            wczytany = true;
                    }
                    else
                        if(matrix.readFromFile2(fileName))
                            wczytany = true;

                }while(!wczytany);
                matrix.show();
                break;
            case '2':
                cout<<"\nEnter maximum allowable time: ";
                cin>>max_time;
                cout<<"Enter cross rate: ";
                cin>>crossRate;
                cout<<"Ente mutation rate: ";
                cin>>mutationRate;
                cout<<"Enter population size: ";
                cin>>pop_size;
                geneticAlgorithm gen = geneticAlgorithm(matrix,pop_size,crossRate,mutationRate, max_time);
                cout<<"Result orderCross: "<<gen.start(0)<<endl;
                cout<<"Result partiallyCross: "<<gen.start(1)<<endl;

            break;
        }
        }while(option!='0');


}