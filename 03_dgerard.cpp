/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   03_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/03 22:21:34 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/03 23:08:40 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

const int   MAX_NAMES = 20;

int         getNames(string names[]){


    int     numNames = 0;

    cout << "enter the names you wish to be sorted, one at a time. when you are"
        " done, enter the string \"DONE\"" << endl;
    while (numNames < MAX_NAMES && (numNames <= 0 || names[numNames - 1] != "DONE")){
        cin >> names[numNames];
        numNames++;
    }
    return numNames;
}

int         main(){

    int     numNames;
    string  names[MAX_NAMES];

    getNames();
    sort();
    printNames();
    return 0;
}
