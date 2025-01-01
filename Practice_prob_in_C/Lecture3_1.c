#include <stdio.h>
#include <string.h>

#define NOT_FOUND -1

int numbers[] = {101, 202, 303, 404, 505, 606, 707}; // Example numbers
char *names[] = {"Alice", "Bob", "Charlie", "Diana", "Evan", "Fiona", "George"}; // Example names
int n = sizeof(names) / sizeof(names[0]); // Number of elements in the array

int myFindNumber(char *person, int low, int high) {
    if (low > high) return NOT_FOUND;
    int P = (low + high) / 2;
    if (strcmp(person, names[P]) == 0) 
        return numbers[P];
    else if (strcmp(person, names[P]) < 0)
        return myFindNumber(person, low, P-1);
    else
        return myFindNumber(person, P+1, high);
}

int findNumber(char *person) {
    return myFindNumber(person, 0, n - 1);
}

int main() {
    char *person = "Fiona"; // Example search
    int number = findNumber(person);
    if (number != NOT_FOUND) {
        printf("Number for %s is %d\n", person, number);
    } else {
        printf("%s was not found\n", person);
    }
    return 0;
}
