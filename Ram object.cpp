//명품 c++ 156p 12번
#include<iostream>
using namespace std;
class Ram{
    char mem[100*1024];
    int size;
public:
    Ram(){
        size=sizeof(mem);
        for(int i=0;i<size;i++){
            mem[i]=0;
        }
    }
    char read(int address){
        return this->mem[address];
    }
    void write(int address,char value){
        mem[address]=value;
    }
    ~Ram(){
        cout<<"메모리 제거됨"<<endl;
    }
};

int main()
{
    Ram ram;
    ram.write(100,20);
    ram.write(101,30);
    char res=ram.read(100)+ram.read(101);
    ram.write(102,res);
    cout<<"102 번지의 값 = "<<(int)ram.read(102)<<endl;

    return 0;
}
