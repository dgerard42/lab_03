/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   02_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/31 12:01:45 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/02 01:26:06 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

int     binarySearch(int sortedArray[], int value, int start, int end){

    int     index = end - ((end - start) / 2);
    
    if (sortedArray[index] == value)
        return index;
    else if (start == end)
        return -1;
    else if (sortedArray[index] > value)
        binarySearch(sortedArray, value, start, index);
    else if (sortedArray[index] < value)
        binarySearch(sortedArray, value, index, end);
}

int     main(){

    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
        
    cout << binarySearch(arr, 3, 0, 9) << endl;
    return 0;
}
