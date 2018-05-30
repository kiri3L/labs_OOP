#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>



class House
{
    int house_number;
    int number_of_floors;
    int number_of_entrances;
public:
    House(int number, int floors,int entrances)
    {
        this->house_number = number;
        this->number_of_floors = floors;
        this->number_of_entrances = entrances;
    }
    int get_floors()
    {
        return this->number_of_floors;
    }
    int get_entrances()
    {
        return this->number_of_entrances;
    }
    int get_number()
    {
        return this->house_number;
    }
    friend std::ostream& operator<<(std::ostream &os, const House &h);

};

std::ostream& operator<<(std::ostream &os, const House &h)
{
    os<<"number "<<h.house_number<<"\n\tentrances "<<h.number_of_entrances<<"\n\tfloors "<<h.number_of_floors<<"\n\n";
    return os;
}
void print(std::vector<House> v)
{
    int i, s = v.size();
    for(i = 0; i < s; i++)
        std::cout<<i+1<<"\t"<<v[i];
}

bool comp( House H1, House H2)
{
    return (H1.get_entrances() < H2.get_entrances());
}

int main()
{
    std::vector<House> vec;
    int i,j,a,b,c,n;
  //  srand(time(NULL));
    std::cout<<"Enter number of Houses\n";
    std::cin>>n;
    std::cout<<"\n\n";
    for(i = 0; i < n; i++)
    {
        a = rand() % 100 + 1;
        b = rand() % 20 + 1;
        c = rand() % 5 + 1;

        vec.push_back(House(a,b,c));
    }
    print(vec);

    std::cout<<"\n\n\tSORT BY NUMBER\n";
    for(i = 0; i < n; i++)
        for(j = 0; j < n - 1; j++)
        {
            if(vec[j].get_number() > vec[j+1].get_number())
                std::swap(vec[j],vec[j+1]);
        }
    print(vec);

    std::cout<<"\n\n\tSORT BY FLOORSE\n";
    std::vector<House>:: iterator it_i ;
    std::vector<House>:: iterator it_j ;
    std::vector<House>:: iterator it_k;
    for(it_i = vec.begin(); it_i != vec.end(); it_i++)
    {
        for(it_j = vec.begin(); it_j != (vec.end()) - 1; it_j++)
        {
            it_k = it_j;
            it_k++;
            if((*it_j).get_floors() > (*it_k).get_floors())
            {
                std::swap(*it_j,*it_k);
            }
        }
    }
    print(vec);

    std::cout<<"\nSORT BY ENTRANCES\n";
    sort(vec.begin(),vec.end(),&comp);
    print(vec);

    return 0;
}
