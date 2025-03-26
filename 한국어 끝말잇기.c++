#include<iostream>

using namespace std;

class WordGame{
private:
    int howManyPeople;

    class Player{
    public:
        string name;
        string sayWord;
    };

    string startword;

public:

    Player*P=nullptr;

    void setPeople() {
        cout<<"게임에 참가하는 인원은 몇명입니까?";
        cin>>this->howManyPeople;

        P = new Player[howManyPeople];

        for(int i=0 ; i < howManyPeople ; i++){
            cout<<"참가자의 이름을 입력하세요. 빈칸 없이>>";
            cin>> P[i].name;
        }
    }

    void gameStart(){
        this->startword="아버지";
        cout<<"시작하는 단어는 "<<this->startword<<"입니다"<<endl;
    }

    void playingGame(){
        int turn=0;
        bool firstRound=true;

        string prevWord;

        while(1){
            if(firstRound){
                prevWord=startword;
                firstRound=false;
            }

            cout<<P[turn].name<<">>";
            cin>>P[turn].sayWord;

            int prevL = prevWord.length();

            if(prevWord.at(prevL-3)==P[turn].sayWord.at(0)
                && prevWord.at(prevL-2)==P[turn].sayWord.at(1)
                && prevWord.at(prevL-1)==P[turn].sayWord.at(2)) {
                prevWord=P[turn].sayWord;
                turn++;
                if(turn==howManyPeople) turn=0;
            } else {
                cout<<"땡~~ "<<P[turn].name<<"씨 탈락~!"<<endl;
                break;
            }
            

        }
    }
};

int main()
{
    WordGame G;

    G.setPeople();

    G.gameStart();

    G.playingGame();

    return 0;
}
