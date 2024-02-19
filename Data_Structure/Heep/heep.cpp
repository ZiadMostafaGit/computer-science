#include <iostream>
#include <vector>
#include<cmath>

using namespace std;



class Heep{

private:
    int*array{};
    int size;
public:
    int lift(int index){
        int p=(2*index)+1;
        if(p>=size)
            return -1;
        else
            return p;    


    }    

    int right(int index){

        int p=(2*index)+2;
        if(p>=size)
            return -1;

        else
        return p;
    }

    int perant(int index){
        int p=floor((index-1)/2);
        if(p==0)
          return -1;
        else
            return index;



    }





};