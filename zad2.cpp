#include <iostream>

using namespace std;


void przelicz(float km){

    cout<<km<<" kilometrow to "<<km*0.53996<<" mil morskich"<<endl;
    cout<<km<<" kilometrow to "<<km*0.621<<" mil lądowych"<<endl;

}

int main(){
    float odleglosc;
    cout<<"Podaj odleglosc w kilometrach: ";
    cin >> odleglosc;
    przelicz(odleglosc);
    
}