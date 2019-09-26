#include"HC.h"

int main(int argc,char** argv){
    int Generation = atoi(argv[1]);
    int Dimension = atoi(argv[2]);
    int Run = atoi(argv[3]);

    hc Hc(Generation,Dimension,Run);
    Hc.hill_climbing();
}