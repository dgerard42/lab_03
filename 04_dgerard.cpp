/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   04_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/06 13:39:53 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/06 22:46:58 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

using namespace std;

/*
    I used https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm as a
    reference for figuring out the time struct
*/

int         getDate(int *dayPtr, int *monthPtr, int *yearPtr){
    
    time_t now = time(0);
    tm  *timeStruct = localtime(&now);
    
    *yearPtr = 1900 + timeStruct->tm_year;
    *monthPtr = timeStruct->tm_mon + 1;                 //since months are not usually zero indexed, I +1'd
    *dayPtr = timeStruct->tm_mday;
    return 0;
} 

int         main(){
    
    int     day;
    int     month;
    int     year;
    
    getDate(&day, &month, &year);
    cout << "today is day " << day << " in month " << month << " and in year " << year " of the Common Era" << endl;
    return 0;
}
