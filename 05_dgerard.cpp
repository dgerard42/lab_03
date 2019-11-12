/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   05_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/06 22:47:10 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/08 20:10:06 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int*        resizeArray(int array[], int size){

    int     *newArray = new int[size * 2];
    int     index = 0;

    while (index < size){
        newArray[index] = array[index];
        index++;
    }
    while (index < (size * 2)){
        newArray[index] = 0;
        index++;
    }
    return newArray;
}

void        printArray(int array[], int size){

    for (int index = 0; index < size; index++){
        cout << array[index];
        if (index + 1 != size)
            cout << ", ";
    }
    cout << endl;
    return;
}

int         main(){

    int     array00[3] = {1,2,3};
    int     array01[1] = {0};
    int     array02[12] = {-2, 4, 42, 69, 33498469, -66666, 0, 9, 8, 7, 6, -5};
    int     *newArray;
    
    printArray(array00, 3);
    newArray = resizeArray(array00, 3);
    printArray(newArray, 6);
    delete newArray;
    newArray = nullptr;
    
    printArray(array01, 1);
    newArray = resizeArray(array01, 1);
    printArray(newArray, 2);
    delete newArray;
    newArray = nullptr;

    printArray(array02, 12);
    newArray = resizeArray(array02, 12);
    printArray(newArray, 24);
    delete newArray;
    newArray = nullptr;

    return 0;
}
