#ifndef GAME_H
#define GAME_H
#include<vector>
#include<string>
using namespace std;
class Nation{
public:
    string name;
    string capital;
    Nation(string n, string c){
        this->name=n;
        this->capital=c;
    }
};

class Game{
    vector<Nation> n;
public:
    Game();

    void run();

    bool existence(string left, string right);

    void info();

    void quiz();
};


#endif