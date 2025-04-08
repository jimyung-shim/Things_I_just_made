#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

class UpAndDownGame{
    class Person{
        string name;
        int answ;
    public:
        Person(){}
        Person(string n){
            this->name=n;
        }
        Person(const Person&p){
            this->name=p.name;
        }
        void setAnsw(){
            cin>>this->answ;
        }

        int getAnsw(){
            return this->answ;
        }
        void setName(string n){
            this->name=n;
        }
        string getName(){
            return this->name;
        }
    };

    int randAnswer;
    int max=99,min=0;
    Person insu;
    Person eunkyeong;

public:
    UpAndDownGame(){
        insu.setName("김인수");
        eunkyeong.setName("오은경");
        cout<<"Up & Down 게임을 시작합니다."<<endl;
        this->randAnswer=rand()%100;
    }

    void setRange(int x){
        if(x>this->randAnswer){
            max=x;
        }else if(x<this->randAnswer){
            min=x;
        }
    }


    void runGame(){
        Person turn(insu);
        while(1){
            cout << "답은 "<<min<<"과 "<<max<<"사이에 있습니다."<<endl;
            cout<<turn.getName()<<">>";
            turn.setAnsw();
            if(turn.getAnsw()==randAnswer){
                cout<<turn.getName()<<"가 이겼습니다!"<<endl;
                break;
            }
            else setRange(turn.getAnsw());

            if(turn.getName()==insu.getName()){
                turn.setName(eunkyeong.getName());
            }else if(turn.getName()==eunkyeong.getName()){
                turn.setName(insu.getName());
            }

        }
    }
};

int main()
{
    srand((unsigned)time(0));

    UpAndDownGame G;
    G.runGame();

    return 0;
}
