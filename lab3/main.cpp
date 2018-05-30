#include <iostream>

class Producer
{
private :
    std::string prod_name;
public :
    Producer(std::string name)
    {
        this->prod_name = name;
    }
    std::string get_prod_name()
    {
        return this->prod_name;
    }
};

class Film
{
private :
    std::string film_name;
    Producer *prod_ptr;

public :
    Film(std::string name, Producer *ptr)
    {
        this->film_name = name;
        this->prod_ptr = ptr;
    }
    Producer* get_prod_of_film()
    {
        return prod_ptr;
    }
};

class Actor
{
private :
    std::string actor_name;
    Film *film_list[100];
    int size_of_array = 0;
public :
    Actor(std::string name, int size_arr, Film *arr[])
    {
        int i;
        this->actor_name = name;
        this->size_of_array = size_arr;
        for(i = 0; i < size_arr; i++ )
        {
            this->film_list[i]= arr[i];
        }
    }
    void add_film(Film *ptr)
    {
        this->size_of_array++;
        this->film_list[size_of_array - 1] = ptr;
    }
    void get_prod()
    {
        int i;
        for(i = 0; i < size_of_array; i++ )
        {
           std::cout<<film_list[i]->get_prod_of_film()->get_prod_name()<<std::endl;
        }
    }

};




int main()
{
    Producer Vasa("Vasa");
    Producer Masha("Masha");
    Film Film1("Film1",&Vasa);
    Film Film2("Film2",&Vasa);
    Film Film3("Film3",&Masha);
    Film Film4("Film4",&Masha);
    Film Film5("Film5",&Masha);
    Film *film_list[2] = { &Film1, &Film2};
    Actor Amir("Amir",2,film_list);
    Amir.get_prod();
    Amir.add_film(&Film4);
    std::cout << std::endl;
    Amir.get_prod();
    return 0;
}
