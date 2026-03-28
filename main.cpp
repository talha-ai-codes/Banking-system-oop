#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout << "enter a and b: ";
    cin >> a >> b;
    cout << "==before swaping==" << endl;
    cout << "a : " << a << endl;
    cout << "b  : " << b << endl;
    cout << "==swap a and b ===" << endl;
    int c = a;
    a = b;
    b = c;
    cout << "===after swaping===" << endl;
    cout << "a : " << a  << endl;
    cout << "b  : " << b << endl;
    return 0;
    
}