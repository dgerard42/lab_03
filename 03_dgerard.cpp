/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   03_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/03 22:21:34 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/29 21:49:58 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int   MAX_NAMES = 20;

/*
    I used http://www.algolist.net/Algorithms/Sorting/Quicksort, Kieran, and
    Toaster as references for the quicksort in this code.
*/

void        printNames(string names[], int numNames){

    int     nameIndex = 0;

    while (nameIndex < numNames){
        cout << names[nameIndex];
        if (nameIndex != numNames - 1)
            cout << ", ";
        nameIndex++;
    }
    cout << endl;
    return;
}

void        quickSort(string array[], int leftWall, int rightWall){

      int       left = leftWall;
      int       right = rightWall;
      string    temp;
      char      pivot = tolower(array[(left + right) / 2][0]);

      if (left >= right)
        return;
      while (left <= right) {
            while ((left < rightWall) && (!isalpha(array[left][0])) || ((isalpha(array[left][0])) && tolower(array[left][0]) < pivot))
                left++;
            while (isalpha(array[right][0]) && (tolower(array[right][0]) > pivot))
                right--;
            if (left <= right) {
                temp = array[left];
                array[left] = array[right];
                array[right] = temp;
                left++;
                right--;
            }
      }
      if (leftWall < right)
            quickSort(array, leftWall, right);
      if (left < rightWall)
            quickSort(array, left, rightWall);
}

int         getNames(string names[]){

    int     numNames = 0;

    cout << "enter the names you wish to be sorted, one at a time. when you are"
        " done, enter the string \"DONE\"" << endl;
    while (numNames < MAX_NAMES && (numNames <= 0 || names[numNames - 1] != "DONE")){
        cout << "Enter a name: ";
        cin >> names[numNames];
        cout << endl;
        numNames++;
    }
    return numNames - 1;
}

int         main(){

    int     numNames;
    string  names[MAX_NAMES];

    numNames = getNames(names);
    names[numNames] = "";
    names[numNames + 1] = "";
    quickSort(names, 0, numNames - 1);
    printNames(names, numNames);
    return 0;
}
