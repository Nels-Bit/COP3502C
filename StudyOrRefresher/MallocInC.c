#include <stdio.h>
#include <stdlib.h>


int main(){

    //malloc() = A function in C that dynamically allocates a specified number of bytes in memory

    //this exmaple asks a user for amount of grades to make an array for that many grades
    
    int number = 0;
    printf("Enter the number of grades: ");
    scanf("%d", &number);

    //char grades [7] = {0}; would work only if we already know the amount

    //in this we return a pointer from malloc
    char *grades = malloc(number * sizeof(char));

    if (grades == NULL){
        printf ("Memory allocation failed");
        exit(1);
    }


    //we use "number" because that is technically the size of the array
    for (int i = 0; i < number; i++){
        
        printf("Enter Grade: #%d: ", i + 1);
        scanf(" %c", &grades[i]);

    }

    for (int i = 0; i < number; i++){

        printf(" %c", grades[i]);

    }

    /*

    we are passing the number of grades by the byte size of a char. 
    So, 4 grades = 4 * 1 = 4 bytes
    How much memory do we need to reserve?
    
    */

    //since malloc technically "rents" that memory, we should free it whenever down
    free(grades);

    grades = NULL; //this avoids dangling point


    return 0;
}