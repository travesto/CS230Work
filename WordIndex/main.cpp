#include <iostream>
#include <vector>
#include <fstream>
#include "word.h"
// #include "ignore.h"
// #include "syn.h"
using namespace std;

int main(int argc, char* argv[])
{
    string book_path = argv[1];
    ifstream file;
    file.open(book_path.c_str());
    vector<string> listOfWords;
    string words;
    if (file.is_open())
    {
        cout << "Is open.";
        while (! file.eof())
        {
            getline(file, words);
            listOfWords.push_back(words);   
        }
    }
    cout << endl << "Size is: " << listOfWords.size() << endl;
    for (int n = 0; n < listOfWords.size(); n++)
    {
        cout << listOfWords[n] << endl;
    }

    // ifstream fileBook, fileIgnore, fileSyn;
    // fileBook.open("book.txt");
    // fileIgnore.open("ignore.txt");
    // fileSyn.open("synonyms.txt");
    // getline(fileBook, listOfWords);
}

    // get word
    // put in vector
    // new line ++line
    // blank line ++paragraph
    
