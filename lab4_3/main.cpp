#include <iostream>

//static int i = 1, j = 1;

class Subject
{
private:
    std::string Subject_name;
    int mark;
public:
    Subject(std::string name, int m = 0)
    {
        this->Subject_name = name;
        this->mark = m;
        std::cout<<"\nSubject born\n";
    }
    ~Subject()
    {
        std::cout<<"\nSubject died\n";
    }
    void say()
    {
        std::cout<<"\nHi\n";
    }
};

class Gradebook
{
private:
    Subject **Subject_list;
    int size_of_list;
public:
    Gradebook(Subject **list, int size)
    {
        this->Subject_list = new Subject*[100];
      //  std::cout << "create " << Subject_list<<std::endl<< i++ << std::endl;
        this->size_of_list = size;
        int i;
        for(i = 0; i < size; i++)
        {
            Subject_list[i] = list[i];
        }
        std::cout<<"\nGradebook born\n";
    }
    void set_subject(Subject *subj)
    {
        this->Subject_list[this->size_of_list] = subj;
        this->size_of_list++;
    }
    ~Gradebook()
    {
        int i;
        for(i = 0; i < this->size_of_list; i++)
        {

            //std::cout << "delete " << Subject_list[i] <<std::endl<< j++ << std::endl;
            delete this->Subject_list[i];
           // std::cout<<"\ni work\n";
        }
        std::cout << "delete ";// << Subject_list <<std::endl<< j++ <<std::endl;
        delete[] Subject_list;
        std::cout<<"\nGradebook died\n";
    }
    void get_size()
    {
        std::cout<<this->size_of_list;
    }
};

class Student
{
private:
    std::string Student_name;
    Gradebook *book;
public:
    Student(std::string name, Gradebook *ptr)
    {
        this->Student_name = name;
        this->book = ptr;
        std::cout<<"\nStudent born\n";
    }
    ~Student()
    {
        std::cout << "delete ";// << book <<std::endl<< j++ <<std::endl;

        delete book;
        std::cout<<"\nStudent died\n";
    }
    void get_name()
    {
        std::cout<<this->Student_name<<std::endl;
    }
};


int main()
{
    {
        Subject *A = new Subject("A",5);
       // std::cout << "create " << A <<std::endl<< i++ << std::endl;
        Subject *B = new Subject("B");
       // std::cout << "create " << B <<std::endl<< i++ << std::endl;
        Subject *C = new Subject("C",4);
       // std::cout << "create " << C <<std::endl<< i++ << std::endl;
        Subject *D = new Subject("D",5);
      //  std::cout << "create " << D <<std::endl<< i++ <<std::endl;
        Subject **ptr = new Subject*[3];
      //  std::cout << "create " << ptr <<std::endl<< i++ <<std::endl;
        ptr[0] = A;
        ptr[1] = B;
        ptr[2] = C;
        Gradebook *book = new Gradebook(ptr,3);
       // std::cout << "create " << book <<std::endl<< i++ <<std::endl;
      //  book->get_size();
        book->set_subject(D);
      //  book->get_size();
        Student *Kirill = new Student("Kirill",book);
      //  std::cout << "create " << Kirill <<std::endl<< i++ << std::endl;
        int j;
        Kirill->get_name();
       // std::cin>>j;
      //  std::cout << "delete " << ptr <<std::endl<< j++ << std::endl;
        delete ptr;
       // std::cout << "delete " << Kirill <<std::endl<< j++ <<std::endl;

        delete Kirill;
        int i;
      //  std::cin>>i;
    }

}
