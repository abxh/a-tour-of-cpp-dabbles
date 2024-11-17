
#include <string>

typedef int Elem;

Elem* next_elem();
void exit(int);
double sqrt(double);
double sqrt(double d);

void print(int);
void print(double);
void print(std::string);

void user()
{
    print(42);
    print(9.65);
    print("D is for Digital");
}

void print(int, double);
void print(double, int);

void user2()
{
    // print(0,0);
    print(0., 0);
}
