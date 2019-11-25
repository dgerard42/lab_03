/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   08_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/25 12:12:08 by doot              _/_/`           `'"`   */
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

char    rot13(char original, bool encryptionDirection){
    
    char    result = original;
    int     encryption = (encryptionDirection == true) ? 13 : -13;

    if (original >= LOWERCASE_A && original <= LOWERCASE_Z){
        if (original - LOWERCASE_A < ALPHA_CHARS - encryption)
            result = original + encryption;
        else
            result = (((original - LOWERCASE_A) + encryption) % ALPHA_CHARS) + LOWERCASE_A;
    } else if (original >= UPPERCASE_A && original <= UPPERCASE_Z){
        if (original - UPPERCASE_A < ALPHA_CHARS - encryption)
            result = original + encryption;
        else
            result = (((original - UPPERCASE_A) + encryption) % ALPHA_CHARS) + UPPERCASE_A;
    }        
    return result;
}

char    rot5(char original, bool encryptionDirection){

    char    result = original;
    int     encryption = (encryptionDirection == true) ? 5 : -5;

    if (original >= CHAR_0 && original <= CHAR_9){
        if (original - CHAR_0 < NUM_CHARS - encryption)
            result = original + encryption;
        else
            result = (((original - CHAR_0) + encryption) % CHAR_0) + CHAR_0;
    }
    return result;
}

string  translateLine(string line, bool encryptionDirection){

    string  result (line.length(), ' ');

    for (int index = 0; index < line.length(); index++){
        result[index] = rot13(line[index], encryptionDirection);
        result[index] = rot5(line[index], encryptionDirection);
    }
    return result;
}

string  getUserInput(string userMessage){
            
    string  userInput = "BLANK STRING";

    cout << userMessage << endl;
    cin >> userInput;

    return userInput; 
}

int    askDirection(){

    int     encryptionDirection;
    string  userInput;

    cout << "would you like to encrypt or decrypt the file?";
    cout << " type \"e\" for encryption, or \"d\" for decryption:" << endl;
    cin >> userInput;
    if (userInput == "e")
        encryptionDirection = 1;
    else if (userInput == "d")
        encryptionDirection = 0;
    else {
        cout << "that was not valid input. please try again." << endl;
        encryptionDirection = -1;
    }
    return encryptionDirection;
}

int     main(){

    ifstream    inputFile;
    ofstream    outputFile;
    string      currentLine;
    string      inputRequest = getUserInput("enter the name of the file you wish to change");
    string      outputRequest = getUserInput("enter the name of the file where you would like to store the results");
    int         encryptionDirection = askDirection();
    
    inputFile.open(inputRequest);
    outputFile.open(outputRequest);
    if (encryptionDirection == -1)
        cout << "exiting program now" << endl;
    else if (inputFile && outputFile){
        while (getline(inputFile, currentLine)){
           currentLine = translateLine(currentLine, encryptionDirection);
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
