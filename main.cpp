#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//recusively finds the longest non-chopped string
string findlongeststringin(string checkString) {


    cout << "checking string: " << checkString << endl;
    cout << "size of current checked string is: " << checkString.size() << endl;

    if (checkString.at(checkString.size() - 1) == ('.') || checkString.at(checkString.size() - 1) == (' ')) {
        cout << "good substring found : " << checkString << endl;
        return checkString;
    } else {
        cout << "Word is chopped" << endl;
        return findlongeststringin(checkString.substr(0, checkString.size() - 1));
    }
}

int main() {

    cout << "This program reads text from a inputFileStream, trims to the desired width, and saves it to a new file"
         << endl;

    int width = 20;
    ifstream inputFileStream("input.txt", ios::in);
    ofstream outputFileStream("outputfile.txt", ios::out);

    //Arraylist to hold the formatted strings
    vector<string> formattedOutput;

    //Temporary strings
    string filecontents;
    string str;

    //Read input inputFileStream line by line into a single string, filecontents
    while (getline(inputFileStream, str)) {
        filecontents += str;
    }
    cout << "checking filecontents : ";
    cout << filecontents << endl;
    cout << "number of characters: " << filecontents.size() << endl;

    //Process the input
    int a = 0;
    int b = a + width;
    while (a < filecontents.size()) {                                       //until we have read every character
        cout << "finding substring from " << a << " and " << b << endl;
        //cout << filecontents.substr(a, b) << endl;           //SOMETHING GOING WRONG HERE
        str = findlongeststringin(
                filecontents.substr(a, b - a));              //use recursive method to find valid substring
        formattedOutput.push_back(str);                                    //add trimmed string to output
        a = a + str.size();                                                //update next start index
        b = a + width;                                                     //update next possible end index
        cout << "new a = " << a << endl;                                   //console logs to confirm
        cout << "new b = " << b << endl;
    }


    //Write results from output array of trimmed strings to the file and close
    for (int i = 0; i < formattedOutput.size(); i++) {
        cout << "writing to file: " << formattedOutput[i] << endl;
        outputFileStream << formattedOutput[i] << endl;
    }
    outputFileStream.close();
    return 0;
}