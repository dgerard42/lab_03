/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   03_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/03 22:21:34 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/04 18:05:51 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int   MAX_NAMES = 20;

void        printNames(string names[], int numNames){

    int     nameIndex = 0;

    while (nameIndex < numNames - 1){
        cout << names[nameIndex];
        if (nameIndex != numNames - 2)
            cout << ", ";
        nameIndex++;
    }
    cout << endl;
    return;
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
    return numNames;
}

int         main(){

    int     numNames;
    string  names[MAX_NAMES];

    numNames = getNames(names);
    //sort();
    printNames(names, numNames);
    return 0;
}
