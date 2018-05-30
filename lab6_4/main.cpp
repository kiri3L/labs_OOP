#include<iostream>

class House
{
private:
    std::string street;
protected:
    int house_nomber;
public:
    std::string town;
    House()
    {
    }
    House(std::string t, std::string s, int n)
    {
        this->town = t;
        this->street = s;
        this->house_nomber = n;
    }
    void print()
    {
        std::cout<<"\n\n"<<this->town <<std::endl;
        std::cout<<this->street <<std::endl;
        std::cout<<this->house_nomber <<std::endl;
    }
    void set_town(std::string t)
    {
        this->town = t;
    }
    void set_street(std::string s)
    {
        this->street = s;
    }
    void set_nomber(int n)
    {
        this->house_nomber = n;
    }
    ~House()
    {
        std::cout<<"\n~House"<<std::endl;
    }
};




class Apartment_house : public House
{
private:
    int count_of_flat;
public:
    Apartment_house(std::string t, std::string s, int n, int c) : House(t,s,n)
    {
        this->count_of_flat = c;
    }
    void print()
    {
        House::print();
        std::cout<<this->count_of_flat<<std::endl;
    }
    void set_count_of_flat(int c)
    {
        this->count_of_flat = c;
    }
    ~Apartment_house()
    {
        std::cout<<"\n~Apartament_house"<<std::endl;
    }
};

class Private_house : private House
{
  private:
    std::string owner;
  public:
    Private_house(std::string t,std::string s, int n, std::string o ) : House(t,s,n)
    {
        this->owner = o;
    }
    void print()
    {
        House::print();
        std::cout<<this->owner<<std::endl;
    }
    void set_owner(std::string o)
    {
         this->owner = o;
    }
    ~Private_house()
    {
        std::cout<<"\n~Private_house"<<std::endl;
    }
};



int main()
{
    std::cout<<"Hello world"<<std::endl;
    House *Dom1 = new House("Mos","len",10);
    Dom1->print();
    Apartment_house *Dom2 = new Apartment_house("Mos","petr",12,244);
    Dom2->print();
    Private_house *Dom3 = new Private_house("Pitert","Mosc",123,"katy");
    Dom3->print();
    delete Dom1;
    delete Dom2;
    delete Dom3;
    return 0;
}
