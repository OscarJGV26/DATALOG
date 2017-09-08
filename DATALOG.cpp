#include "DATALOG.h"
using namespace std;
void DATALOG::begin(){
    printf("Initializing Data Logging\n");
    myfile.open("/media/SD/example.txt");
    if(myfile.is_open()!=1){
        printf("File didnt open... Terminating program for safety.\n");
    }
    myfile.setf(ios::fixed, ios::floatfield);
    myfile.precision(2);
    printf("Data Logging Initialized!\n");
}
void DATALOG::write(float imu_data[], float motors[],float references[],float mat1[], float mat2[], float mat3[],float gain1[],float gain2[], float gain3[]){
    if(myfile.is_open()){
        for(int i=0;i<9;i++){
            myfile<<imu_data[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<motors[i];
            myfile<<",";
        }
        for(int i=0;i<6;i++){
            myfile<<references[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<mat1[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<mat2[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<mat3[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<gain1[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<gain2[i];
            myfile<<",";
        }
        for(int i=0;i<4;i++){
            myfile<<gain3[i];
            myfile<<",";
        }
        myfile<<"\r\n";
        myfile.flush();
    }
}
void DATALOG::open(){
    if(myfile.is_open()!=1) 
    {
        myfile.open("/media/SD/example.txt");
        myfile.setf(ios::fixed, ios::floatfield);
        myfile.precision(2);
    }
    counter=0;
}
void DATALOG::close(){
    if(counter<limit)counter++;
    if(counter>=limit)
    {
        printf("Closing file... ");
        myfile.close();
        printf("File closed!\n");
    }
}
