/*
COP3502C | Spring 2026 | Section 0001
Name: Nelson Fleitas
UCF ID: 5686463
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *title;  /* dynamically allocated string (exact size) */
    int  pages;   /* number of pages */
} Book;

/* --------- Helpers --------- */

/* Read a single token, allocate exact-fit string, and return it. */
static char *read_token_alloc(void) {
    char buf[256];
    if (scanf("%255s", buf) != 1) return NULL;
    char *p = (char*)malloc(strlen(buf) + 1);
    if (!p) return NULL;
    strcpy(p, buf);
    return p;
}

/* --------- Functions students must implement --------- */

/* Read n and then read n books into a Book** array; return the array and set *count. */
Book **readBooks(int *count) {
    /* TODO:
       - read *count
       - allocate Book** array of size *count (or NULL if 0)
       - for each book:
           * malloc Book
           * read title token (using read_token_alloc) and pages
           * store pointer in array
       - return Book** array
    */

    scanf("%d", count);
    Book **arr = (Book**)malloc(*count * sizeof(Book*));

    for (int i = 0; i < *count; i++) {
        // allocate
        arr[i] = (Book*)malloc(sizeof(Book));

        // read titles
        arr[i]->title = read_token_alloc();

        // read pages
        scanf("%d", &arr[i]->pages);
    }


    return arr;
}

/* Print all books exactly as: "<title> <pages>\n" */
void printBooks(Book **arr, int count) {
    /* TODO:
       - loop from 0..count-1 and print each book
    */

    for (int i = 0; i < count; i++){
        // arr[i] is a pointer so must use arrow
        printf("%s %d\n", arr[i]->title, arr[i]->pages);

    }
}

/*
 * Remove a book by title (if present).
 * Returns the (possibly reallocated) Book** pointer.
 * Caller pattern: arr = removeBook(arr, &count, title);
 * Behavior:
 *  - find index by strcmp
 *  - free(arr[idx]->title); free(arr[idx]);
 *  - shift elements left to fill the gap
 *  - --(*count)
 *  - if *count == 0 -> free array and return NULL
 *    else -> attempt to shrink with realloc and return the (maybe new) pointer
 *  - if title not found, return the original arr unchanged
 */
Book **removeBook(Book **arr, int *count, const char *title) {
    /* TODO */

    for (int i = 0; i < *count; i++){

        //compares current index title with target
        int titleCompare = strcmp(arr[i]->title, title);

        //free stuff in the container then the container
        if (titleCompare == 0){
            free(arr[i]->title);
            free(arr[i]);
            *count = *count -1;

            // shift to the left
            for (int j = i; j < *count; j++){
                arr[j] = arr[j + 1];
            }

            // is list empty? if so free else reallocate
            if (*count == 0) {
                free(arr);
                return NULL;
            } else {
                arr = realloc(arr, *count * sizeof(Book*));
                return arr;
            }
        }
    }

    return arr;
}

/* Free every Book (title then struct), then the array itself. */
void freeBooks(Book **arr, int count) {
    /* TODO */
    for (int i = 0; i < count; i++){

        free(arr[i]->title);
        free(arr[i]);

    }

    free(arr);
}

/* --------- Driver --------- */

int main(void) {
    int count = 0;
    Book **arr = readBooks(&count);

    int q = 0;
    if (scanf("%d", &q) != 1) q = 0;

    while (q--) {
        int t = 0;
        if (scanf("%d", &t) != 1) break;

        if (t == 1) {
            /* print all */
            printBooks(arr, count);
        } else if (t == 2) {
            /* remove by title (silent) */
            char *title = read_token_alloc();
            if (title) {
                arr = removeBook(arr, &count, title);  /* no triple pointer */
                free(title);
            }
        }
    }

    freeBooks(arr, count);
    return 0;
}
