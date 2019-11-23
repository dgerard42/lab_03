/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   07_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/19 10:54:17 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/22 16:22:26 by dany              _/_/`           `'"`   */
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

clock_t    startClock(){

     clock_t    start = clock();
     return start;
}

void      endClock(clock_t start){
    
    cout << "Time: " << (clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << endl;
    return;
}

int     main(){
    
    clock_t time;

    time = startClock();
    cout << ackermann(1,2) << endl;
    endClock(time);
    time = startClock();
    cout << ackermann(2,2) << endl;
    endClock(time);
    time = startClock();
    cout << ackermann(3,3) << endl;
    endClock(time);
    time = startClock();
    cout << ackermann(4,0) << endl;
    endClock(time);
    time = startClock();
    cout << ackermann(4,1) << endl;
    endClock(time);

}
