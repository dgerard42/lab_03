/* ************************************************************************** */
/*                                                                            */
/*                                                  .--.                      */
/*   06_dgerard.cpp                              __/ o  ".                    */
/*                                              `  ),    "-.                  */
/*   By: dany <github.com/dgerard42>               |;;,      "-._             */
/*                                                 ';;;,,    ",_ "=-._        */
/*   Created: 2019/11/08 20:10:35 by dany            ':;;;;,,..-``"-._`"-.    */
/*   Updated: 2019/11/22 15:52:39 by dany              _/_/`           `'"`   */
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
        << fileName << "\" was succesful. (ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ the string was found "
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

string          getUserInput(string userMessage){
    
    string      userInput = "BLANK STRING";

    cout << userMessage << endl;
    cin >> userInput;

    return userInput; 
}

/*
    initialize the first item of the vector to zero, will be reassigned to one if any matches
    are found. while the file can be read line by line, search each line for the user's
    search phrase. add the line numbers of the found matches to the vector
*/

void            readThru(ifstream& inputFile, string fileRequest, string searchRequest, vector<int>& matchLineNums){
    
    int         lineNumber = 1;
    string      currentLine;
        
    matchLineNums.push_back(0);
    while(getline(inputFile, currentLine)){
        if (currentLine.find(searchRequest) != std::string::npos){
            matchLineNums.push_back(lineNumber);
            matchLineNums[0] = 1;
        }
        lineNumber++;
    }
    return;
}

/*
    Check to make sure that cin hasn't failed to get the user's input. if it has not failed,
    open the file. Check to see that open was successful. if it was, read through, print info,
    and then close the file. If the file didn't open, alert the user 
*/

int             main(){
    
    ifstream    inputFile;
    string      fileRequest = getUserInput("enter the name of the file you wish to search");
    string      searchRequest = getUserInput("enter the word or phrase you wish to search for");
    vector<int> matchLineNums;

    if (fileRequest != "BLANK STRING" && searchRequest != "BLANK STRING")
        inputFile.open(fileRequest);
    if (inputFile){
        readThru(inputFile, fileRequest, searchRequest, matchLineNums);
        printInfo(matchLineNums, fileRequest, searchRequest);
        inputFile.close();
    } else {
        cout << "this file won't open" << endl;
    }
    return 0;
}
