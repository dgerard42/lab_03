/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   08_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/24 23:26:55 by doot              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string    INPUT_FILE = "janeEyre.txt";
const int       LINES = 289;
const string    OUTPUT_FILE = "output.txt";

const char      UPPERCASE_A = 65;
const char      UPPERCASE_Z = 90;
const char      LOWERCASE_A = 97;
const char      LOWERCASE_Z = 122;
const char      ALPHA_CHARS = 26;

/*
    read the file in
    make a distinct function for rot13 that takes one char
*/

char    rot13(char original){
    
    char    encrypted = '#';

    if (original >= LOWERCASE_A && original <= LOWERCASE_Z){
        if (original - LOWERCASE_A < ALPHA_CHARS - 13)
            encrypted = original + 13;
        else
            encrypted = (((original - LOWERCASE_A) + 13) % ALPHA_CHARS) + LOWERCASE_A;
    } else if (original >= UPPERCASE_A && original <= UPPERCASE_Z){
        if (original - UPPERCASE_A < ALPHA_CHARS - 13)
            encrypted = original + 13;
        else
            encrypted = (((original - UPPERCASE_A) + 13) % ALPHA_CHARS) + UPPERCASE_A;
    }        
    return encrypted;
}

/*
int     main(){
    
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
*/
