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
    string file1 = "ftv33.atsp";
    string file2 = "ftv47.atsp";
    string file3 = "ftv70.atsp";
    string file4 = "ftv170.atsp";
    string file5 = "rbg323.atsp";
    ofstream file;
    char option;
    Matrix matrix;
    string fileName="";
    int max_time, pop_size;
    float crossRate, mutationRate;
    bool wczytany = false;
    geneticAlgorithm gen;
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
                gen = geneticAlgorithm(matrix,pop_size,crossRate,mutationRate, max_time);
                cout<<"Result orderCross: "<<gen.start(0)<<endl;
                gen.best_result();
                cout<<"Result partiallyCross: "<<gen.start(1)<<endl;
                gen.best_result();
                break;
            case '3':
                file.open(file1+"_results.txt");
                matrix.readFromFile(file1);
                for(int i  = 60;i<=180;i+=60){
                     // 0.70
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.70,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.80
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix, 1000, 0.80,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.90
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.90,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }

                    //0.05
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.05,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    //0.10
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.1,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                }
                file.close();    

                file.open(file2+"_results.txt");
                matrix.readFromFile(file2);
                 for(int i  = 60;i<=180;i+=60){
                     // 0.70
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.70,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.80
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix, 1000, 0.80,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.90
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.90,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }

                    //0.05
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.05,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    //0.10
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.1,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                }
                

                file.close();  
                 file.open(file3+"_results.txt");
                matrix.readFromFile(file3);
                  for(int i  = 60;i<=180;i+=60){
                     // 0.70
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.70,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.80
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix, 1000, 0.80,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.90
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.90,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }

                    //0.05
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.05,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    //0.10
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.1,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
    
                }
                file.close();
                 file.open(file4+"_results.txt");
                matrix.readFromFile(file4);
                for(int i  = 60;i<=180;i+=60){
                     // 0.70
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.70,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.80
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix, 1000, 0.80,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.90
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.90,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }

                    //0.05
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.05,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    //0.10
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.1,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                }
                file.close();
                 file.open(file5+"_results.txt");
                matrix.readFromFile(file5);
                for(int i  = 60;i<=180;i+=60){
                     // 0.70
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.70,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.70<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.80
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix, 1000, 0.80,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.80<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    // 0.90
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.90,0.01,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.90<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }

                    //0.05
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.05,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.05<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                    //0.10
                    for(int j = 0;j<3;j++){
                        gen = geneticAlgorithm(matrix,1000, 0.80,0.1,i);
                        max_time = gen.start(0);
                        pop_size = gen.start(1);
                        file<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                        cout<<0.01<<";"<<i<<";"<<max_time<<";"<<pop_size<<endl;
                    }
                }
                file.close();         
        }
     }while(option!='0');


}