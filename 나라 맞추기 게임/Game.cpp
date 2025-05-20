#include<iostream>
#include<vector>
#include"Game.h"
using namespace std;

Game::Game(){
    Nation kor("대한민국","서울");
    n.push_back(kor);

    Nation USA("미국","와싱턴");
    n.push_back(USA);

    Nation UK("영국", "런던");
    n.push_back(UK);

    Nation ch("중국", "베이징");
    n.push_back(ch);

    Nation jap("일본","도쿄");
    n.push_back(jap);

    Nation germ("독일", "베를린");
    n.push_back(germ);

    Nation fran("프랑스","파리");
    n.push_back(fran);

    Nation kongo("콩고","브라자빌");
    n.push_back(kongo);

    Nation Aust("호주", "캔버라");
    n.push_back(Aust);
}

void Game::run(){
    while(1){
        cout<<"***** 나라의 수도 맞추기 게임을 시작합니다. *****"<<endl;
        cout<<"정보 입력: 1, 퀴즈: 2, 종료: 3 >> ";
        int option;
        cin >> option;
        if(option==1)info();
        if(option==2)quiz();
        if(option==3)break;
    }
}

bool Game::existence(string left, string right){
    int len=n.size();

    bool exist=false;
    for(int i=0;i<len;i++){
        if(left==n[i].name&&right==n[i].capital)exist=true;
    }

    return exist;
}

void Game::info(){
    cout<<"현재 "<<this->n.size()<<"개의 나라가 입력되어 있습니다.\n나라와 수도를 입력하세요(no no 이면 입력끝)"<<endl;
    while(1){
        string left,right;
        cout<<this->n.size()+1<<">>";
        cin>>left>>right;

        if(left=="no" && right=="no")break;

        if(existence(left, right)){
        cout<<"already exists !!"<<endl;
            continue;
        }
        
        Nation insert(left, right);
        n.push_back(insert);
    }
}

void Game::quiz(){
    int len=this->n.size();
    while(1){
        srand((unsigned)time(0));
        int random=rand()% len;

        cout<<this->n[random].name<<"의 수도는?";
        string cap;
        cin>>cap;

        if(cap=="exit")break;
        
        if(cap==n[random].capital){
            cout<<"Correct !!"<<endl;
        }
        else {
            cout<<"NO !!"<<endl;
        }

    }
}
