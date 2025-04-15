// 명품 c++ 371p 12번
#include<iostream>
using namespace std;

class SortedArray{
    int size;
    int*p;

    void sort(){
        for(int key=0;key<size;key++){
            int min=p[key],index=key;
            for(int j=key+1;j<size;j++){
                if(p[j]<min){
                    min=p[j]; 
                    index=j;
                }
            }
            if(index!=key){
                int temp=this->p[key];
                this->p[key]=this->p[index];
                this->p[index]=temp;
            }
        }
    }

public:
    SortedArray(){
        this->p=nullptr;
        this->size=0;
    }
    SortedArray(SortedArray&src){
        size=src.size;
        this->p=new int[size];
        for(int i=0;i<size;i++){
            this->p[i]=src.p[i];
        }

    }
    SortedArray(int p[],int size){
        this->size=size;
        this->p=new int[size];
        for(int i=0;i<size;i++){
            this->p[i]=p[i];
        }
        sort();
    }

    ~SortedArray(){
        delete[] this->p;
    }

    SortedArray operator+(SortedArray& op2){
        int n = this->size + op2.size;
        int* newArr = new int[n];
        for(int i=0;i<this->size;i++){
            newArr[i]=this->p[i];
        }

        for(int i=0;i<op2.size;i++){
            newArr[i+this->size]=op2.p[i];
        }

        return SortedArray(newArr,n);
    }

    SortedArray& operator=(const SortedArray& op2){
        if(this==&op2)return *this;

        delete [] this->p;
        size=op2.size;
        this->p=new int[size];
        for(int i=0;i<size;i++){
            this->p[i]=op2.p[i];
        }
        return *this;
    }

    void show(){
        cout<<"배열 출력 : ";
        for(int i=0;i<size;i++){
            cout<<this->p[i]<<' ';
        }
        cout<<endl;
    }
};

int main()
{
    int n[]={2,20,6};
    int m[]={10,7,8,30};
    SortedArray a(n,3), b(m,4),c;

    c = a + b;

    a.show();
    b.show();
    c.show();
}
