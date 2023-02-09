#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define STR 50

struct person {
    char name[STR];
    int age;
};

struct person  *add_person_single_pointer(struct person *persons, int *count,int *max, char name[], int age){

    if((*count) < (*max-1)){
        strcpy(persons[*count].name, name);
        persons[*count].age = age;
        (*count)++;

        return persons;

    } else{
        int newMax = (*max) * 2;
        struct person *newList = malloc(newMax * sizeof(struct person));

        for (int i = 0; i < *count; i++) {
            newList[i] = persons[i];
        }

        free(persons);
        persons = newList;
        *max = newMax;

        strcpy(persons[*count].name, name);
        persons[*count].age = age;
        (*count)++;

        return persons;
    }

}

void add_person_double_pointer(struct person **persons, int *count,int *max, char name[], int age){

    if(count < max-1){
        strcpy((*persons)[*count].name, name);
        (*persons)[*count].age = age;
        (*count)++;

    } else{
        int newMax = (*max) * 2;
        struct person *newList = malloc(newMax * sizeof(struct person));

        for (int i = 0; i < *count; i++) {
            newList[i] = (*persons)[i];
        }

        free(*persons);
        *persons = newList;
        *max = newMax;

        strcpy((*persons)[*count].name, name);
        (*persons)[*count].age = age;
        (*count)++;

    }

}

int main() {

    int max = 2;
    int count = 0;
    struct person *persons = malloc(max * sizeof(struct person));

    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);
    persons = add_person_single_pointer(persons, &count, &max, "tiago", 21);
    add_person_double_pointer(&persons, &count, &max, "tiago", 21);


    printf("Count is %d",count);

    return 0;
}





/**
int x = 10;
    int *ptr;
    ptr = &x;

    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", &x);
    printf("Value of ptr: %p\n", ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
*/