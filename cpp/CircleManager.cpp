//명품 c++ 216p 12번 문제
#include<iostream>

using namespace std;

class Circle{
    int radius;
    string name;
public:
    void setCircle(string name, int radius){
        this->name=name;
        this->radius=radius;
    }

    double getArea(){
        return this->radius*this->radius*3.14;
    }

    string getName(){
        return this->name;
    }
};

class CircleManager{
    Circle*p;
    int size;
public:
    CircleManager(int size){
        this->size=size;
        p=new Circle[size];
        for(int i=0;i<size;i++){
            cout<<"원 "<<i+1<<"의 이름과 반지름 >> ";
            string n;
            int r;
            cin>>n>>r;
            p[i].setCircle(n,r);
        }
    }
    ~CircleManager(){
        delete [] p;
    }

    void searchByName(){
        cout<<"검색하고자 하는 원의 이름 >> ";
        string search;
        cin>>search;

        int i;
        for(i=0;i<size;i++){
            if(p[i].getName()==search)break;
        }

        cout<<p[i].getName()<<"의 면적은 "<<p[i].getArea()<<endl;
    }

    void searchByArea(){
        cout<<"최소 면적을 정수로 입력하세요 >> ";
        int min;
        cin>>min;
        cout<<min<<"보다 큰 원을 검색합니다."<<endl;

        for(int i=0;i<size;i++){
            if(p[i].getArea()>min){
                cout<<p[i].getName()<<"의 면적은 "<<p[i].getArea()<<',';
            }
        }
        cout<<endl;
    }
};

int main()
{
    int n;
    cout<<"원의 개수 >> ";
    cin>>n;
    CircleManager C(n);

    C.searchByName();
    C.searchByArea();

    return 0;
}
