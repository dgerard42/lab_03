/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   01_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/10/29 11:58:39 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/10/31 12:01:27 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

const int   BASE = 10;

unsigned int        getPlace(unsigned int number){

    int     place = 0;

    while (number > 0){
        place++;
        number /= BASE;
    }
    return place;
}

unsigned int        reverse(unsigned int number){

    int place = getPlace(number);
        
    if (number == 0)
        return 0;
    else {
        return ((number % BASE) * (pow(BASE, (getPlace(number) - 1))) + reverse(number / BASE));
    }
}

int                 main(){

    cout << reverse(123) << endl;
    cout << reverse(1234567890) << endl;
    cout << reverse(1230303) << endl;
}
