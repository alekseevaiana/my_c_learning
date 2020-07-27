#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char* name;
    char* country;
    int age;
} person;

void print_person_profile(person p)
{
    printf("Hello! My name is %s. I am %d years old and I come from %s\n\n", p.name, p.age, p.country);
}

person* create() {

    
    person* Dawit = malloc(sizeof(Dawit));

    Dawit->name = "Dawit";
    Dawit->country = "Ethiopia";
    Dawit->age = 29;

    return Dawit;
}
person* create2() {
    person* Dawit = malloc(sizeof(Dawit));

    Dawit->name = "Hello";
    Dawit->country = "Ethiopia";
    Dawit->age = 29;

    return Dawit;
}

int main()
{
    person* Dawit = create();
    create2();

    printf("Char: %c\n", Dawit->name[0]);


    //print_person_profile(*Dawit);
    return 0;
}