#ifndef __HC_H__
#define __HC_H__

#include<iostream>
#include<string>
#include<bitset>
#include<cstdlib>
#include<ctime>
//#define Gen 10000
//#define run 20
//#define dimension 100
using namespace std;

class hc{
public:
    bitset<100> bits;

    string s;
    string neighbor;
    int Max;
    int temp;
    int times;
    int Best;
    int Worst;
    double avg;

    int Gen;
    int Dimension;
    int Run;
    
    hc(int gen,int dimension,int run);
    void hill_climbing();
    string NextNeighbor(string s,int dimension);
    string determination(string s,string neighbor,int dimension);
    int fitness(string s,int dimension);
};



#endif