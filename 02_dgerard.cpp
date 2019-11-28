/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   02_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/31 12:01:45 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/27 22:03:58 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int     binarySearch(int sortedArray[], int value, int start, int end){

    int     index = end + start / 2;
//    cout << start << "!!!!!" << end << endl;
   
    if (sortedArray[index] == value)
        return index;
    else if (start == index)
        return -1;
    else if (sortedArray[index] > value)
        binarySearch(sortedArray, value, start, index - 1);
    else if (sortedArray[index] < value)
        binarySearch(sortedArray, value, index + 1, end);
}

int     main(){

    int arr0[10] = {0,1,2,3,4,5,6,7,8,9};
    int arr1[1] = {5};
    int arr2[1] = {0};
    int arr3[5] = {-342425, -1, 0, 3, 34322};
        
    cout << binarySearch(arr0, 9, 0, 9) << endl;
    cout << binarySearch(arr0, 0, 0, 9) << endl;
    cout << binarySearch(arr1, 5, 0, 0) << endl;
    cout << binarySearch(arr1, -2, 0, 0) << endl;
    cout << binarySearch(arr2, 0, 0, 0) << endl;
    cout << binarySearch(arr3, 34322, 0, 4) << endl;
    cout << binarySearch(arr3, -342425, 0, 4) << endl;
    return 0;
}
