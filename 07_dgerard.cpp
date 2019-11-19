/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   07_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/19 10:54:17 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/19 12:17:23 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

using namespace std;


long    ackermann(int m, int n){
    
    if (m == 0)
        return (n + 1);
    if (n == 0)
        return ackermann((m - 1), 1);
    else
        return ackermann((m - 1), ackermann(m, (n - 1)));
}

int     main(){

    cout << ackermann(1,2) << endl;
    cout << ackermann(2,2) << endl;
    cout << ackermann(3,3) << endl;
    cout << ackermann(4,0) << endl;
}
