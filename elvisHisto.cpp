#include<iostream>

using namespace std;

class Histogram{
    string text;
    int aplphabet[26];
    int alNum;
public:
    Histogram(string str){
        this->text=str;
        this->text+='\n';
        this->alNum=0;
        for(int i=0;i<26;i++)aplphabet[i]=0;
    }

    void put(string addTxt){
        this->text.append(addTxt);
    }

    void putc(char c){
        this->text+=c;
    }

    void calculate(){
        int len=this->text.length();
        for(int i=0;i<len;i++){
            if(isalpha(this->text[i])){
                this->alNum++;
                this->text[i]=tolower(this->text[i]);
                aplphabet[this->text[i]-'a']++;
            }
        }
    }

    void print(){
        cout<<this->text<<endl;
        calculate();
        cout<<endl;
        cout<<"총 알파벳 수 "<<this->alNum<<endl;
        cout<<endl;

        for(int i=0;i<26;i++){
            char c=i+'a';
            cout << c<<" ("<<this->aplphabet[i]<<")  : ";
            for(int j=0;j<this->aplphabet[i];j++)cout<<'*';
            cout<<endl;
        }
    }
};

int main()
{
    Histogram elvisHisto("Wise men say, only fools rush in But I can't help, ");
    elvisHisto.put("falling in love with you");
    elvisHisto.putc('-');
    elvisHisto.put("Elvis Presley");
    elvisHisto.print();
}
