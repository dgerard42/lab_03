/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   04_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/06 13:39:53 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/06 17:07:47 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

/*
    I used https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm as a
    reference 
*/

int         getDate(int *dayPtr, int *monthPtr, int *yearPtr){
    
    time_t now = time(0);
    tm  *timeStruct = localtime(&now);
    
//    cout << 1900 + timeStruct->tm_year << endl;
    *yearPtr = 1900 + timeStruct->tm_year;
    return 0;
} 

int         main(){
    
    int     day;
    int     month;
    int     year;
    
    getDate(&day, &month, &year);
//    cout << "today is " <<;
    return 0;
}
