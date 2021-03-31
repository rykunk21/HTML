/*
For this problem, you will need to sort a list of whitespace separated 
integers using three different sort algorithms (described here: 
http://theoryapp.com/selection-insertion-and-bubble-sort/ and 
https://en.wikipedia.org/wiki/Insertion_sort).

Your program will output the state of the initial list of numbers and 
also after each swap for each of the three sorting algorithms (selection, 
insertion, and bubble). Note: You want to use the version of insertion 
sort from Wikipedia.

Do not perform swaps if they don't change the vector.
*/


int main(){
    // inp = 1 6 3 8 4 2 3 9 2 4

    /*
    correct output
    Selection Sort
    1 6 3 8 4 2 3 9 2 4 
    1 2 3 8 4 6 3 9 2 4 
    1 2 2 8 4 6 3 9 3 4 
    1 2 2 3 4 6 8 9 3 4 
    1 2 2 3 3 6 8 9 4 4 
    1 2 2 3 3 4 8 9 6 4 
    1 2 2 3 3 4 4 9 6 8 
    1 2 2 3 3 4 4 6 9 8 
    1 2 2 3 3 4 4 6 8 9 
    Insertion Sort
    1 6 3 8 4 2 3 9 2 4 
    1 3 6 8 4 2 3 9 2 4 
    1 3 6 4 8 2 3 9 2 4 
    1 3 4 6 8 2 3 9 2 4 
    1 3 4 6 2 8 3 9 2 4 
    1 3 4 2 6 8 3 9 2 4 
    1 3 2 4 6 8 3 9 2 4 
    1 2 3 4 6 8 3 9 2 4 
    1 2 3 4 6 3 8 9 2 4 
    1 2 3 4 3 6 8 9 2 4 
    1 2 3 3 4 6 8 9 2 4 
    1 2 3 3 4 6 8 2 9 4 
    1 2 3 3 4 6 2 8 9 4 
    1 2 3 3 4 2 6 8 9 4 
    1 2 3 3 2 4 6 8 9 4 
    1 2 3 2 3 4 6 8 9 4 
    1 2 2 3 3 4 6 8 9 4 
    1 2 2 3 3 4 6 8 4 9 
    1 2 2 3 3 4 6 4 8 9 
    1 2 2 3 3 4 4 6 8 9 
    Bubble Sort
    1 6 3 8 4 2 3 9 2 4 
    1 3 6 8 4 2 3 9 2 4 
    1 3 6 4 8 2 3 9 2 4 
    1 3 6 4 2 8 3 9 2 4 
    1 3 6 4 2 3 8 9 2 4 
    1 3 6 4 2 3 8 2 9 4 
    1 3 6 4 2 3 8 2 4 9 
    1 3 4 6 2 3 8 2 4 9 
    1 3 4 2 6 3 8 2 4 9 
    1 3 4 2 3 6 8 2 4 9 
    1 3 4 2 3 6 2 8 4 9 
    1 3 4 2 3 6 2 4 8 9 
    1 3 2 4 3 6 2 4 8 9 
    1 3 2 3 4 6 2 4 8 9 
    1 3 2 3 4 2 6 4 8 9 
    1 3 2 3 4 2 4 6 8 9 
    1 2 3 3 4 2 4 6 8 9 
    1 2 3 3 2 4 4 6 8 9 
    1 2 3 2 3 4 4 6 8 9 
    1 2 2 3 3 4 4 6 8 9 
    
    */
}