#include <iostream>
#include "lista.hpp"
#include "dinstring.cpp"
#include "karta.hpp"
#include "dinKarta.hpp"
#include "putovanje.hpp"
using namespace std;

int main()
{
    avionskaKarta a1;
    avionskaKarta a2("London","Dubai",5,479.66,9000,1);
    cout<<a1.getStart()<<endl;
    cout<<a1.getFinish()<<endl;
    cout<<a1.getLen()<<endl;
    cout<<a1.getPrice()<<endl;
    cout<<a1.getId()<<endl;
    a1.print();
    cout<<a2.getStart()<<endl;
    cout<<a2.getFinish()<<endl;
    cout<<a2.getLen()<<endl;
    cout<<a2.getPrice()<<endl;
    cout<<a2.getId()<<endl;
    a2.print();
    avionskaKarta a3("Madrid","Rome",1,365.79,400,3);
    Putovanje p1;
    p1.print();
    p1.addKartu(a1);
    p1.print();
    p1.addKartu(a2);
    p1.print();
    p1.addKartu(a3);
    p1.print();
    Putovanje p2("Travel 2020",9999);
    avionskaKarta a4("Sarajevo","Jerusalem",1,991.17,150,4);
    p2.addKartu(a2);
    p2.addKartu(a4);
    p2.print();
    p2.deleteKartu(105);
    p2.print();
    cout<<p2.getName()<<endl;
    cout<<p2.getMaxPrice();
    return 0;
}
