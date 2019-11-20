/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/19 15:59:38 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void            printInfo(vector<int> lineNumbers, string fileName, string searchRequest){
    
    if ( lineNumbers[0] != 0){
        cout << "your search for the phrase: \"" << searchRequest << "\" in the document \""
        << fileName << "\" was succesful. (✿ ◕ᗜ◕)━♫.*･｡ﾟ the string was found "
        << (lineNumbers.size() - 1) << " time(s) at the following line numbers:" << endl;
        for (int index = 1; index < lineNumbers.size(); index++){
            cout << lineNumbers.at(index) << endl;
        }
    }   
    else
        cout << "your search for the phrase: \"" << searchRequest << "\" in the document \""
        << fileName << "\" has failed.  o͡͡͡╮༼ • ʖ̯ • ༽╭o͡͡͡  please try again." << endl;
    return;
}

int             searchLine(string haystack, string needle){

    int         match = 0;
    int         search = 0;
    int         haystackLen = haystack.length();
    int         needleLen = needle.length();
    int         foundStatus = 0;
    
    while (search < haystackLen && haystack[search] != needle[match])
        search++;
    while (match + search <= haystackLen && match <= needleLen && haystack[match + search] == needle[match])
        match++;
    if (match == needleLen)
        foundStatus = 1;
    return foundStatus;
}

/*
    Unfortunately, this menthod ^^^ is shitty and incomplete because
    1. it cannot find the word if there is a partial match and then a full match later in the string
    2. it cannot find the phrase if it is larger than the line
    you're going to have to re write this whole thing
*/

string          getUserInput(string userMessage){
    
    string      userInput;

    cout << userMessage << endl;
    cin >> userInput;

    return userInput; 
}

int             main(){
    
    string      currentLine;
    ifstream    inputFile;
    //string      fileRequest = getUserInput("enter the name of the file you wish to search");
    //string      searchRequest = getUserInput("enter the word or phrase you wish to search for");
    string      fileRequest = "janeEyre.txt";
    string      searchRequest = "Jane";
    vector<int> matchPageNums;
    int         lineNumber = 1;

    if (fileRequest != "void")
        inputFile.open(fileRequest);
    if (inputFile){
        matchPageNums.push_back(0);
        while(getline(inputFile, currentLine)){
            if (searchLine(currentLine, searchRequest)){
                matchPageNums.push_back(lineNumber);
                matchPageNums[0] = 1;
            }
            lineNumber++;
        }
        printInfo(matchPageNums, fileRequest, searchRequest);
        inputFile.close();
    } else {
        cout << "this file won't open" << endl;
    }
    return 0;
}
