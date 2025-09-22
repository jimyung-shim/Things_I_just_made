#include<iostream>

using namespace std;

class Person{
    string name;
public:
    Person(){}
    void set(string name){
        this->name=name;
    }
    string getName(){
        return this->name;
    }
};

class Family{
    Person*p;
    int size;
public:
    Family(string name, int size):size(size){
        p=new Person[size];
        cout<<name<<"가족은 다음과 같이 "<<size<<"명 입니다."<<endl;
    }

    void show(){
        for(int i=0;i<size;i++){
            cout<<p[i].getName()<<"\t";
        }
    }

    void setName(int index, string name){
        p[index].set(name);
    }

    ~Family(){
        delete [] p;
    }
};

int main()
{
    Family*simpson=new Family("Simpson",3);
    simpson->setName(0,"Mr. Simpson");
    simpson->setName(1,"Mrs. Simpson");
    simpson->setName(2, "Bart Simpson");
    simpson->show();
    delete simpson;

    return 0;
}
