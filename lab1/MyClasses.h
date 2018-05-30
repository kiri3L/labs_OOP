#ifndef MYCLASSES_H_INCLUDED
#define MYCLASSES_H_INCLUDED
#define STUDENT_AGE_OR_SURNAME  12

#include <iostream>

class Subject
{
private:
    std::string Subject_name;
    int mark;
public:
    Subject(std::string name, int m );
    ~Subject();
};

class Gradebook
{
private:
    Subject **Subject_list;
    int size_of_list;
public:
    Gradebook(Subject **list, int size);
    ~Gradebook();
    void set_subject(Subject *subj);
    void get_size();
};

class Student
{
private:
    std::string Student_name;
    Gradebook *book;
#if STUDENT_AGE_OR_SURNAME == 1
    int student_age;
#else // STUDENT_AGE_OR_SURNAME
    std::string student_surname;
#endif // STUDENT_AGE_OR_SURNAME
public:
    #if STUDENT_AGE_OR_SURNAME == 1
    Student(std::string name, int ag, Gradebook *ptr);
    #else
    Student(std::string name, std::string sur, Gradebook *ptr);
    #endif
    ~Student();
    void tell_about_yourself();


};

#endif
