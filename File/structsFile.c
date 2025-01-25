#include <stdio.h>

typedef struct Person
{
    char name[256];
    int age;
    int balance;

}Person;








int main(){
    FILE*file=open("Person.txt","w+");
    Person persona1={"Martin",10,1000};

    


}