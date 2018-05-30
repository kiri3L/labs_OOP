#include <iostream>

class Human
{
private:
    std::string name;
public:
    Human(std::string n)
    {
        this->name = n;
    }
    virtual void print()
    {
        std::cout<<name<<": ";
    }
    virtual ~Human()
    {
       std::cout<<" ~Human"<<std::endl;
    }
};

class Student : public Human
{
public:
    Student(std::string n) : Human(n)
    {

    }
    virtual void print() override
    {
        Human::print();
        std::cout<<"I am tired"<<std::endl;
    }
    virtual ~Student()
    {
        std::cout<<"~Student"<<std::endl;
    }
};

class Professor : public Human
{
public:
    Professor(std::string n) : Human(n)
    {

    }
    virtual void print() override
    {
        Human::print();
        std::cout<<"physics is cool"<<std::endl;
    }
    virtual ~Professor()
    {
        std::cout<<"~Professor"<<std::endl;
    }
};



int main()
{
    Professor *Einstein = new Professor("Einstein");
    Student *Anton = new Student("Anton");
    Einstein->print();
    Anton->print();
    return 0;
}
