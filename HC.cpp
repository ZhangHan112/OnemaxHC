#include "HC.h"

hc::hc(int gen,int dimension,int run){
    srand(time(NULL));

    Gen = gen;
    Dimension = dimension;
    Run = run;
    times=0;
    Best=10000000;
    Worst=0;
    avg=0;
    Max=0;
    temp=0;
    
}
void hc::hill_climbing(){
    for(int r=0;r<Run;r++){
      for(int i=0;i<Dimension;i++) //決定起點
            bits[i] = rand()%2;
        s  = bits.to_string();

        for(int iter=0;iter<Gen;iter++){ //最多執行的回合數
            
            neighbor = NextNeighbor(s,Dimension);
            temp = fitness(s,Dimension);
            s = determination(s,neighbor,Dimension);
            
            int temp = fitness(s,Dimension);
            times++;
            if(temp==Dimension) break; 
        }
        cout << times << " times." << endl;
        if(Best>times) Best = times;
        if(Worst<times) Worst = times;
        avg += times;
        times = 0;
    }
    avg /= Run;
    
    cout << "============================" << endl;
    cout << "Best: " << Best << " times." <<endl;
    cout << "Worst: " << Worst << " times." <<endl;
    cout << "Average: " << avg << " times." <<endl;
    cout << "============================" << endl;
    
}
string hc::NextNeighbor(string s,int dimension){
    int pos1,pos2;
    pos1 = rand()%dimension;
    pos2 = rand()%dimension;
    if(s.at(pos1)=='1') s[pos1]='0';
    else s[pos1]='1';
    //if(s.at(pos2)=='1') s[pos2]='0';
    //else s[pos2]='1';
    


    return s;
}

int hc::fitness(string s,int dimension){
    int temp;
    for(int i=0; i<dimension; i++){
        if(s[i]=='1')
            temp++;
    }
    return temp;
}

string hc::determination(string s,string neighbor,int dimension){
    if(fitness(neighbor,dimension)>fitness(s,dimension))
        s = neighbor;
    return s;
}