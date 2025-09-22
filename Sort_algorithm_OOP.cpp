#include<iostream>

using namespace std;

class sorter{
private:
    int n;
    int arr[100];
public:
    sorter(int n){
        this->n=n;

        for(int i=0;i<this->n;i++){
            arr[i]=rand()%100;
        }

        showArr();
    }

    void showArr(){
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void selectionSort(){
        int key;
        for(key=0;key<n;key++){
            int index=key;
            int min=arr[key];
            for(int j=key;j<n;j++){
                if(arr[j]<min){
                    min=arr[j];
                    index=j;
                }
            }
            int temp=arr[key];
            arr[key]=arr[index];
            arr[index]=temp;
        }
    }

    void bubbleSort(){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }

    ~sorter(){
        for(int i=0;i<n;i++){
            arr[i]=0;
        }
    }
};

int main(){
    sorter S(9);

    S.bubbleSort();
    S.showArr();

    return 0;
}
