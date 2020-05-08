#ifndef KARTA_HPP_INCLUDED
#define KARTA_HPP_INCLUDED
class Karta
{
protected:
    DinString start;
    DinString finish;
    float len;
    float price;
    int id;
public:
    Karta()
    {
        start = "Stockholm";
        finish = "Belgrade";
        len = 1,621.97;
        price = 320;
        id = 0;
    }

    Karta(DinString s, DinString f, float l, float p, int i)
    {
        start = s;
        finish = f;
        len = l;
        price = p;
        id = i;
    }

    virtual bool jeftinaKarta() = 0;
    DinString getStart()const
    {
        return start;
    }

    DinString getFinish()const
    {
        return finish;
    }

    float getLen()const
    {
        return len;
    }

    float getPrice()const
    {
        return price;
    }

    int getId()const
    {
        return id;
    }

};


#endif // KARTA_HPP_INCLUDED
