#include <iostream>
#include "MyClasses.cpp"



int main()
{
    {
        Subject *A = new Subject("A",5);
        Subject *B = new Subject("B");
        Subject *C = new Subject("C",4);
        Subject *D = new Subject("D",5);
        Subject **ptr = new Subject*[3];

        ptr[0] = A;
        ptr[1] = B;
        ptr[2] = C;
        Gradebook *book = new Gradebook(ptr,3);

        book->set_subject(D);

        Student *Kirill = new Student("Kirill", "Kirillov", book);
        Kirill->tell_about_yourself();
        delete ptr;
        delete Kirill;
    }

}
