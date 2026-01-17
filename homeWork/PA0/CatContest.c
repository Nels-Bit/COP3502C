#include <stdio.h>
#include <string.h>
#include "Cat.h"

int main(void){
    
    // declaring the array withouts MALLOC, MAXCATS is defined in header
    struct cat allCats[MAXCATS];

    // variable top store actual amount of cats
    int numCats = 0;

    // read all the data
    readData(allCats, &numCats);

    // print the list of all cats first
    for(int i = 0; i < numCats; i++){
        printf("%d %s %d %d %d %.2f\n", 
            allCats[i].cat_ID, 
            allCats[i].name, 
            allCats[i].score1, 
            allCats[i].score2, 
            allCats[i].score3, 
            allCats[i].average
        );
    }

    // returns the index of the winner
    int winnerIndex = getCutestCat(allCats, numCats);

    printf("Cutest cat is %s\n", allCats[winnerIndex].name);

    int letterCounts[26] = {0};

    for (int i = 0; i < numCats; i++){

        // get first letter of cat name 
        char firstLetter = allCats[i].name[0];

        // find out which letter it is C(67) - A(65)  = 2
        int index = firstLetter - 'A';

        // add 1 to that index to calculate total
        letterCounts[index]++;

    }

    for (int i = 0; i < 26; i++){

        // helps with output, goes through the alphabet
        char currentLetter = i + 'A';

        // number of times we saw that letter / total cats * 100
        float percentage = (float)letterCounts[i] / (float)numCats * 100;

        // output formatted as need (ex. A: 1 10.00%)
        printf("%c: %d %.2f%%\n", currentLetter, letterCounts[i], percentage);
    
    }

}

void readData(struct cat *cats, int *count){

    // receive total number of cats
    scanf("%d", count);

    // loop through and assing data to cat
    for(int i = 0; i < *count; i++){
        scanf("%d", &cats[i].cat_ID);
        scanf("%s", cats[i].name);
        scanf("%d", &cats[i].score1);
        scanf("%d", &cats[i].score2);
        scanf("%d", &cats[i].score3);
        
        // calculate average to later decide winner
        cats[i].average = (float)(cats[i].score1 + cats[i].score2 + cats[i].score3) / 3;
    }   

}

int getCutestCat(struct cat *cats, int n){

    // assume first is cutest
    int winner = 0;

    // simple loop that compares 1 to n-1
    for (int i = 1; i < n; i++){
        if (cats[i].average > cats[winner].average){
            winner = i;
        }
    }

    // return index of winner
    return winner;

}