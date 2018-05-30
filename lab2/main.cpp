#include <iostream>

class Composer
{
    std::string composer_name;
    int  birth_year;
    std::string genre;
public:
    Composer(std::string name, int b_year, std::string genre)
    {
        this->composer_name = name;
        this->birth_year = b_year;
        this->genre = genre;
    }

    std::string get_name()
    {
        return this->composer_name;
    }
    int get_year()
    {
        return this->birth_year;
    }
    std::string get_genre()
    {
        return this->genre;
    }
};

bool comp_by_name(Composer &C1, Composer &C2)
{
    return (C1.get_name() > C2.get_name());
}

bool comp_by_year(Composer &C1, Composer &C2)
{
    return (C1.get_year() > C2.get_year());
}

bool comp_by_genre(Composer &C1, Composer &C2)
{
    return (C1.get_genre() > C2.get_genre());
}

void sort_composer(int number_of_composers, Composer *composers, bool(*comp)(Composer &C1, Composer &C2))
{
    int i,j;
    for(j = 0; j < number_of_composers; j++)
    {
        for(i = 0; i < number_of_composers - 1; i++)
        {
            if(comp(composers[i],composers[i+1]))
            {
                std::swap(composers[i],composers[i+1]);
            }
        }
    }
}
void print_NYG(Composer &composer)
{
    std::cout<<composer.get_name()<<"\n"<<composer.get_year()<<"\n"<<composer.get_genre()<<"\n";
}

void print_GNY(Composer &composer)
{
    std::cout<<composer.get_genre()<<"\n"<<composer.get_name()<<"\n"<<composer.get_year()<<"\n";
}

void print_YGN(Composer &composer)
{
    std::cout<<composer.get_year()<<"\n"<<composer.get_genre()<<"\n"<<composer.get_name()<<"\n";
}

void print_composers(int number_of_composers, Composer *composers, void(*print)(Composer &composer))
{
    int i;
    for(i = 0; i < number_of_composers; i++)
    {
        print(composers[i]);
        std::cout<<"\n\n";
    }
    std::cout<<"\n\n";
}


int main()
{
    Composer compos[] = {Composer("Wolfgang Amadeus Mozart",1756,"classic music"),
                         Composer("Ludwig van Beethoven",1770,"classic music"),
                         Composer("Antonio Salieri",1750,"classic music"),
                         Composer("David Gilmour",1946,"psychedelic rock"),
                         Composer("Syd Barrett",1946,"psychedelic rock")};
    print_composers(5,compos,&print_NYG);
    std::cout<<"SORT BY NAME\n\n";
    sort_composer(5,compos,&comp_by_name);
    print_composers(5,compos,&print_NYG);
    std::cout<<"SORT BY YEAR\n\n";
    sort_composer(5,compos,&comp_by_year);
    print_composers(5,compos,&print_YGN);
    std::cout<<"SORT BY GENRE\n\n";
    sort_composer(5,compos,&comp_by_genre);
    print_composers(5,compos,&print_GNY);
    return 0;
}
