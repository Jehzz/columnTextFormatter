#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    cout << "This program reads text from a inputFileStream, trims to the desired width, and saves it to a new file" << endl;

    int width = 20;
    ifstream inputFileStream("input.txt", ios::in);
    ofstream outputFileStream("outputfile.txt", ios::out);

    //Arraylist to hold the formatted strings
    vector<string> formattedOutput;

    //Temporary strings
    string filecontents;
    string str;

    //Read input inputFileStream line by line into a single string, filecontents
    while (getline(inputFileStream,str))
    {
        filecontents += str;
    }
    cout << "checking filecontents : ";
    cout << filecontents <<endl;
    cout << "number of characters: " << filecontents.size();

    //TRIM FILECONTENT SUBSTRINGS, APPEND TO FORMATTEDOUTPUT
    //TO-DO


    //Write results from array of trimmed strings and close
    for (int i = 0; i < formattedOutput.size(); i++){
        cout << "writing output to file";
        outputFileStream << formattedOutput[i];
    }
    outputFileStream.close();
    return 0;
}