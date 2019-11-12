/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   readFile.cpp                                __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/11 21:12:09 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string    INPUT_FILE = "janeEyre.txt";
const int       LINES = 289;
const string    OUTPUT_FILE = "output.txt";

int             main(){
    
    string      currentLine;

    ifstream    inputFile;
    inputFile.open(INPUT_FILE);

    ofstream    outputFile;
    outputFile.open(OUTPUT_FILE);

    if (inputFile && outputFile){
        for (int line = 0; line < LINES; line++){
            getline(inputFile, currentLine);
            outputFile << currentLine << endl;
        }
        inputFile.close();
        outputFile.close();
    } else {
        cout << "this file won't open" << endl;
    }
    return 0;
}
