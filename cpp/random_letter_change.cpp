#include<iostream>

using namespace std;

int main(){
    cout<<"Enter a line.(When you enter 'exit', then it'll be end)"<<endl;
    while(1){
        cout<<">>";
        string line;
        getline(cin,line);
        
        if(line=="exit")break;

        int len=line.length();

        int n=rand()%len;

        char x=97;
        for(;;){
            x=rand()%123;
            if(x>=97)break;
        }

        line.at(n)=x;

        cout<<line<<endl;
    }
    return 0;
}
