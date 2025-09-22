#include<iostream>
//명품 c++ 8단원 실습문제 7번
using namespace std;

class BaseMemory{
    char*mem;
protected:
    BaseMemory(int size){
        this->mem=new char[size];
    }

    void burn(int size, char x[], int inputArrSize){
        if(this->mem != nullptr){
            delete [] this->mem;
            this->mem = new char[size];
        }
        for(int i=0;i<inputArrSize;i++){
            this->mem[i]=x[i];
        }
    }

    char get(int index){
        return this->mem[index];
    }

    void put(int index, char c){
        this->mem[index]=c;
    }
};

class ROM : public BaseMemory{
    int romSize;
public:
    ROM(int size, char x[], int inputArrSize): BaseMemory(size){
        burn(size,x,inputArrSize);
        romSize=inputArrSize;
    }

    char read(int index){
        return get(index);
    }
};

class RAM : public BaseMemory{
public:
    RAM(long size):BaseMemory(size){}

    void write(int index, char c){
        put(index,c);
    }

    char read(int index){
        return get(index);
    }
};

int main(){
    char x[5]={'h','e','l','l','o'};
    ROM biosROM(1024*10, x, 5);
    RAM mainMemory(1024*1024);

    for(int i=0;i<5;i++){
        mainMemory.write(i, biosROM.read(i));
    }

    for(int i=0;i<5;i++){
        cout<<mainMemory.read(i);
    }
}
