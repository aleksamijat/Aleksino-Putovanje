#ifndef PUTOVANJE_HPP_INCLUDED
#define PUTOVANJE_HPP_INCLUDED
#include "karta.hpp"

class Putovanje
{
private:
    DinString name;
    int maxPrice;
    List <karta> karta_;
public:
    Putovanje()
    {
        name = "Putovanje ?";
        maxPrice = 10000;
    }
    Putovanje(DinString n, int m)
    {
        name = n;
        maxPrice = m;
    }
    DinString getName()const
    {
        return name;
    }
    int getMaxPrice()const
    {
        return maxPrice;
    }
    bool addKartu(const karta& a)
    {
        avionskaKarta lastKarta;
        karta_.read(karta_.size(),lastKarta);
        bool exist = true;
        if(karta_.size()==0)
            karta_.add(1,a);
        else if(a.getStart() == lastKarta.getFinish() && a.getPrice() <= maxPrice)
        {
            for(int i = 1;i <= karta_.size();++i)
            {
                karta_.read(i,lastKarta);
                if(lastKarta.getId()==a.getId())
                    exist = false;
            }
            if(exist)
                karta_.add(karta_.size()+1,a);
        }
        else
            exist = false;
        return exist;
    }
    bool removeKarta(int id_)
    {
        avionskaKarta karta;
        for(int i = 1;i < karta_.size();++i)
        {
            karta_.read(i,karta);
            if(karta.getId() == id_)
            {
                karta_.remove(i);
                return true;
            }
        }
        return false;
    }
    void print()
    {
        cout<<"Naziv: "<<name<<endl
        <<"Maksimalna cena: "<<maxPrice<<endl
        <<"Broj karti: "<<karta_.size()<<endl;
        avionskaKarta karta;
        for(int i = 1;i <= karta_.size();++i)
        {
            karta_.read(i,karta);
            karta.print();
            if(karta.jeftinaKarta())
                cout<<"Jeftina karta"<<endl;
            else
                cout<<"Nije jeftina karta"<<endl;
        }
    }
};


#endif // PUTOVANJE_HPP_INCLUDED
