/*
COP3502C | Spring 2026 | Section 0001
Name: Nelson Fleitas
UCF ID: 5686463
*/

int searchRecord(int numbers[], int low, int high, int value){

    if (low > high){
        return -1;
    }

    int mid = (low + high) / 2;

    if (numbers[mid] == value){
        return mid;
    } else if (numbers[mid] > value){
        return searchRecord(numbers, low, mid - 1, value);
    } else {
        return searchRecord(numbers, mid + 1, high, value);
    }

    return 0;
}