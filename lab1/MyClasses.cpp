#include "MyClasses.h"


Subject::Subject(std::string name, int m = 0)
{
    this->Subject_name = name;
    this->mark = m;
    std::cout<<"\nSubject born\n";
}

Subject::~Subject()
{
    std::cout<<"\nSubject died\n";
}


Gradebook::Gradebook(Subject **list, int size)
{
    this->Subject_list = new Subject*[100];
    this->size_of_list = size;
    int i;
    for(i = 0; i < size; i++)
    {
        Subject_list[i] = list[i];
    }
    std::cout<<"\nGradebook born\n";
}

Gradebook::~Gradebook()
{
    int i;
    for(i = 0; i < this->size_of_list; i++)
    {
        delete this->Subject_list[i];
    }

    delete[] Subject_list;
    std::cout<<"\nGradebook died\n";
}

void Gradebook::set_subject(Subject *subj)
{
    this->Subject_list[this->size_of_list] = subj;
    this->size_of_list++;
}

void Gradebook::get_size()
{
    std::cout<<this->size_of_list;
}

#if STUDENT_AGE_OR_SURNAME ==  1
Student::Student(std::string name, int ag, Gradebook *ptr)
{
    this->Student_name = name;
    this->book = ptr;
    this->student_age = ag;
    std::cout<<"\nStudent born\n";
}
#else
Student::Student(std::string name, std::string sur, Gradebook *ptr)
{
    this->Student_name = name;
    this->book = ptr;
    this->student_surname = sur;
    std::cout<<"\nStudent born\n";
}
#endif // STUDENT_AGE_OR_SURNAME

Student::~Student()
{
    delete book;
    std::cout<<"\nStudent died\n";
}

void Student::tell_about_yourself()
{
    std::cout<<"\n\n"<<this->Student_name<<"\t";
#if STUDENT_AGE_OR_SURNAME == 1
    std::cout<<this->student_age<<" years old"<<std::endl;
#else
    std::cout<<"\n\n"<<this->student_surname<<std::endl;
#endif // STUDENT_AGE_OR_SURNAME

}


