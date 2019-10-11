#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//recursively finds the longest non-chopped string
string findlongeststringin(string checkString) {

    //cout << "checking sub-string: " << checkString << endl;
    if (checkString.at(checkString.size() - 1) == ('.') || checkString.at(checkString.size() - 1) == (' ')) {
        //cout << "good substring found : " << checkString << endl;
        return checkString;
    } else {
        //cout << "Word is chopped" << endl;
        return findlongeststringin(checkString.substr(0, checkString.size() - 1));
    }
}

int main() {

    cout << "This program reads text from input.txt, trims to the desired width, and saves it to a new file, output.txt \n" << endl;

    //Arraylist to hold the formatted strings
    vector<string> formattedOutput;
    string filecontents;
    string str;

    int width;
    cout << "Enter desired column width: ";
    cin >> width;

    //Read input inputFileStream line by line into a single string, filecontents
    ifstream inputFileStream("input.txt", ios::in);
    while (getline(inputFileStream, str)) {
        str += ' ';                                     //pad a space to account for newlines and sentences
        filecontents += str;
    }
    inputFileStream.close();

    //Process the input
    int a = 0;
    int padding = 0;
    while (a < filecontents.size()) {                                       //until we have read every character
        str = findlongeststringin(filecontents.substr(a, width));              //use recursive method to find valid substring
        a += str.length();                                                //update next start index
        padding = width -str.length();                                      //Center text
        for (int i = 0; i < padding/2; i++){
            str = " "+str;                                                  //By inserting leading spaces
        }
        formattedOutput.push_back(str);                                    //add trimmed string to output
    }

    ofstream outputFileStream("outputfile.txt", ios::out);
    cout << "\n \n =======Writing to outputfile.txt=====" << endl;
    for (int i = 0; i < formattedOutput.size(); i++) {              //Write results and close
        outputFileStream << formattedOutput[i] << endl;
        cout << formattedOutput[i] << endl;
    }
    outputFileStream.close();
    return 0;
}