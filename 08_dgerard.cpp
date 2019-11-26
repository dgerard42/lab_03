/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   08_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/26 13:17:49 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const char      UPPERCASE_A = 65;
const char      UPPERCASE_Z = 90;
const char      LOWERCASE_A = 97;
const char      LOWERCASE_Z = 122;
const char      ALPHA_CHARS = 26;
const char      NUM_CHARS = 10;
const char      CHAR_0 = 48;
const char      CHAR_9 = 57;
const int       ALPHA_ENCRYPTION = 13;
const int       NUM_ENCRYPTION = 5;

char    rotAlpha(char original, int rotSize){
    
    char    result = original;

    if (original >= LOWERCASE_A && original <= LOWERCASE_Z){
        if (original - LOWERCASE_A < ALPHA_CHARS - rotSize)
            result = original + rotSize;
        else
            result = (((original - LOWERCASE_A) + rotSize) % ALPHA_CHARS) + LOWERCASE_A;
    } else if (original >= UPPERCASE_A && original <= UPPERCASE_Z){
        if (original - UPPERCASE_A < ALPHA_CHARS - rotSize)
            result = original + rotSize;
        else
            result = (((original - UPPERCASE_A) + rotSize) % ALPHA_CHARS) + UPPERCASE_A;
    }        
    return result;
}

char    rotNum(char original, int rotSize){

    char    result = original;

    if (original >= CHAR_0 && original <= CHAR_9){
        if (original - CHAR_0 < NUM_CHARS - rotSize)
            result = original + rotSize;
        else
            result = (((original - CHAR_0) + rotSize) % NUM_CHARS) + CHAR_0;
    }
    return result;
}

string  translateLine(string line){

    string  result (line.length(), ' ');

    for (int index = 0; index < line.length(); index++){
        if (line[index] >= CHAR_0 && line[index] <= CHAR_9)
            result[index] = rotNum(line[index], NUM_ENCRYPTION);
        else
            result[index] = rotAlpha(line[index], ALPHA_ENCRYPTION);
    }
    return result;
}

string  getUserInput(string userMessage){
            
    string  userInput = "BLANK STRING";

    cout << userMessage << endl;
    cin >> userInput;

    return userInput; 
}

int     main(){

    ifstream    inputFile;
    ofstream    outputFile;
    string      currentLine;
    string      inputRequest = getUserInput("enter the name of the file you wish to change");
    string      outputRequest = getUserInput("enter the name of the file where you would like to store the results");
//    string inputRequest = "output.txt";
//    string outputRequest = "empty.txt";
    
    inputFile.open(inputRequest);
    outputFile.open(outputRequest);
    if (inputFile && outputFile){
        while (getline(inputFile, currentLine)){
           currentLine = translateLine(currentLine);
           outputFile << currentLine << endl;
        }
        inputFile.close();
        outputFile.close();  
    } else {
        cout << "there was a problem opening the input and/or ouput files"
            << " please check your filenames and try again." << endl;
    }
    return 0;
}
