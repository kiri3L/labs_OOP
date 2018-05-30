#include <iostream>

class Food
{
private:
    std::string food_name;
    int calories;
public:
    Food()
    {
        calories = 0;
    }
    Food(std::string name, int cal)
    {
        this->food_name = name;
        this->calories = cal;
    }
    void set_food_name(std::string name)
    {
        food_name = name;
    }
    void set_calories(int cal)
    {
        calories = cal;
    }
    Food operator+(const Food f2)
    {
        Food sum("Food",0);
        sum.calories = this->calories + f2.calories;
        return sum;
    }
    void operator+(const int cal)
    {
        this->calories += cal;
    }
    friend std::ostream& operator<<(std::ostream &os, const Food &f);
    friend std::istream& operator>>(std::istream &os, const Food &f);
};

std::ostream& operator<<(std::ostream &os, const Food &f)
{
    os<<f.food_name<<"  "<<f.calories<<"  calories";
    return os;
}

std::istream& operator>>(std::istream &ist, Food &f)
{
  std::string f_name;
  int cal;
  ist>>f_name>>cal;
  f.set_food_name(f_name);
  f.set_calories(cal);
  return ist;
}

int main()
{
    Food A("Fish",100);
    Food B("Meet",200);
    Food C;
    C = A + B;
    std::cout<<A<<" + "<<B<<" = \n\n\t = "<<C;
    std::cout<<C<<"\n\n Enter food\n\n"<<std::endl;
    std::cin>>C;
    std::cout<<C;
    return 0;
}
