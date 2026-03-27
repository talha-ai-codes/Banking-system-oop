#include<iostream>
using namespace std;
int main(){
    try{
        int *p = new int[10000000000000000000000000];
        cout << "Memory allocated successfully:" << endl;
        delete []p;
    }
    catch(const exception &e){
        cout << "exception occured:" << e.what() << endl;
    }
    

}