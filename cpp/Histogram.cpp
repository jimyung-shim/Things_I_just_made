#include<iostream>
#include<vector>
using namespace std;

class Histogram{
    string text;
    int alphabet[26];
    int alnum;
public:
    Histogram(string txt){
        this->text=txt;
        alnum=0;
        for(int i=0;i<26;i++)alphabet[i]=0;
    }

    Histogram& operator<<(string txt){
        this->text.append(txt);
        return *this;
    }

    Histogram& operator<<(char c){
        this->text+=c;
        return *this;
    }


    void calculate(){
        int len=this->text.length();
        for(int i=0;i<len;i++){
            if( isalpha( text.at(i) ) ) {
                alnum++;
                text.at(i)=tolower(text.at(i));
                alphabet[(int)text.at(i)-97]++;
            }
        }
    }

    Histogram& operator!(){
        cout<<this->text<<endl;
        cout<<endl;
        calculate();
        cout<<"총 알파벳 수 "<<this->alnum<<endl;
        for(int i=97;i<=122;i++){
            cout<<(char)i<<':';
            for(int j=0;j<alphabet[i-97];j++)cout<<'*';
            cout<<endl;
        }

        return *this;
    }
};

int main()
{
    Histogram song("Wise men say, \nonly fools rush in But I can't help, \n");
    song<<"falling"<<" in love with you."<<"- by ";
    song<<'k'<<'i'<<'t';
    !song;
}
