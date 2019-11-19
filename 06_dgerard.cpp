/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/19 11:24:57 by dany              _/_/`           `'"`   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

/*
    read file
    search line
    count matches
    create a vector of line numbers where the match occured
*/

void            printInfo(vector<int> lineNumbers, string fileName, string searchRequest){
    
    if ( lineNumbers[0] ){
        cout << "your search for the phrase: \"" << searchRequest << "\" in the document \""
        << fileName << "\" was succesful. (✿ ◕ᗜ◕)━♫.*･｡ﾟ the string was found "
        << lineNumbers.size() << " time(s) at the following line numbers:" << endl;
        for (int index = 0; index < lineNumbers.size(); index++){
            cout << lineNumbers.at(index) << endl;
        }
    }   
    else
        cout << "your search for the phrase: \"" << searchRequest << "\" in the document \""
        << fileName << "\" has failed.  o͡͡͡╮༼ • ʖ̯ • ༽╭o͡͡͡  please try again.";
    return;
}

int             searchLine(string haystack, string needle){

    int         match = 0;
    int         search = 0;
    int         haystackLen = haystack.length();
    int         needleLen = needle.length();
    int         foundStatus = 0;
    
    while (haystack[search] != needle[match])
        search++;
    while (match + search < haystackLen && match < needleLen && haystack[match + search] == needle[match])
        match++;
    if (needleLen == match || haystackLen == match)
        foundStatus = 1;
    return foundStatus;
}

string          getUserInput(string userMessage){
    
    string      userInput;

    cout << userMessage << endl;
    cin >> userInput;

    return userInput; 
}

int             main(){
    
    string      currentLine;
    ifstream    inputFile;
    string      fileRequest = getUserInput("enter the name of the file you wish to search");
    string      searchRequest = getUserInput("enter the word or phrase you wish to search for");
    vector<int> matchPageNums;
    int         lineNumber = 1;

    if (fileRequest != "void")
        inputFile.open(fileRequest);
    if (inputFile){
        while(getline(inputFile, fileRequest)){
            getline(inputFile, currentLine);
            if (searchLine(currentLine, searchRequest))
                matchPageNums.push_back(lineNumber);
            lineNumber++;
        }
        printInfo(matchPageNums, fileRequest, searchRequest);
        inputFile.close();
    } else {
        cout << "this file won't open" << endl;
    }
    return 0;
}
