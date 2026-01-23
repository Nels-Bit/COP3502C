#ifndef CAT_H
#define CAT_H


#define MAXSTRLEN 10  
#define MAXCATS 500

struct cat
{
    int cat_ID;
    char name[MAXSTRLEN + 1];
    int score1;
    int score2;
    int score3;
    float average;
};

void readData(struct cat *cats, int *c);

int getCutestCat(struct cat *s, int n);

#endif