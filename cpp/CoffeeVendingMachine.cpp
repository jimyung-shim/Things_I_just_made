//명품 c++ 215p 11번 문제
#include<iostream>

using namespace std;

class Container{
    int size;
public:
    Container():size(10){}

    void fill(){
        this->size=10;
    }

    void consume(){
        this->size--;
    }

    int getSize(){
        return this->size;
    }
};

class CoffeeVendingMachine{
    Container tong[3];
    void fill(){
        for(int i=0;i<3;i++){
            tong[i].fill();
        }
        show();
    }

    void selectEspresso(){
        cout<<"에스프레소 드세요"<<endl;
        tong[0].consume();
        tong[1].consume();
    }

    void selectArmericano(){
        cout<<"아메리카노 드세요"<<endl;
        tong[0].consume();
        tong[1].consume();
        tong[1].consume();
    }

    void selectSugarCoffee(){
        cout<<"설탕커피 드세요"<<endl;
        tong[0].consume();
        tong[1].consume();
        tong[1].consume();
        tong[2].consume();
    }

    void show(){
        cout<<"커피 "<<tong[0].getSize()<<", 물 "<<tong[1].getSize()<<", 설탕 "<<tong[2].getSize()<<endl;
    }

public:
    CoffeeVendingMachine(){}
    void run(){
        cout<<"***** 커피자판기를 작동합니다. *****"<<endl;

        while(1){
            cout<<"메뉴를 눌러주세요(1:에스프레소, 2.아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기)>> ";
            int n;
            cin>>n;
            if(n==0)break;
            if(n==1)selectEspresso();
            if(n==2)selectArmericano();
            if(n==3)selectSugarCoffee();
            if(n==4)show();
            if(n==5)fill();
        }
    }
    ~CoffeeVendingMachine(){
    }
};

int main()
{
    CoffeeVendingMachine C;
    C.run();

    return 0;
}
