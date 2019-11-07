/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   05_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/06 22:47:10 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/07 12:06:25 by dany              _/_/`           `'"`   */
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
    delete array;
    *array = nullptr;
    return newArray;
}

void        printArray(int array[], int size){

    for (int index = 0; index < size; index++){
        cout << array[index] << endl;
    }
    return;
}

int         main(){

    int     array[3] = {1,2,3};
    
    printArray(array, 3);
    resizeArray(array, 3);
    printArray(array, 6);
}
