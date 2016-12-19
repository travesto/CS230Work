#include <iostream>
#include <vector>
#include <fstream>
#include "indexLookUp.h"
// #include "ignore.h"
// #include "syn.h"
using namespace std;

string makeLower(string x)
{
    for (int i = 0; i < x[i]; i++)
    {
        x[i] = tolower(x[i]);
    }
    return x;
}

bool isChapter(string word, index &book)
{
    if (makeLower(word).find("chapter") != string::npos)
    {
        double isChapter = makeLower(word).find("chapter") + 8;
        string chapterName;
        for (; isChapter < word.size(); isChapter++)
        {
            if (word[isChapter] == ' ' || word[isChapter] == 0)
            {
                break;
            }
            chapterName += word[isChapter];
        }
        for (int i = 0; chapterName[i-1] != 0; i++) //remove ancillary symbols
        {
            if (chapterName[i] =='.' || chapterName[i] == '?' || chapterName[i] == '!' || chapterName[i] == ',' || chapterName[i] == ';'|| chapterName[i] == ':'|| chapterName[i] == '-' || chapterName[i] == '"' || chapterName[i] == char(39) || chapterName[i] == '_' || chapterName[i] == '(' || chapterName[i] == ')')
            {
                if (i == 0 || i == chapterName.size()-1)
                {
                    chapterName.erase(i,i+1);
                }
            }
        }
        book.addChapter(chapterName);
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    string book_path = argv[1], ig_path = argv[2], syn_path = argv[3];
    fstream file, fileIgnore, fileSyn, fileResults;
    file.open(book_path.c_str());
    fileSyn.open(syn_path.c_str());
    fileIgnore.open(ig_path.c_str());
    // fileResults.open("results.txt");

    index book;
    vector<string> listOfWords;
    int paragraph = 1;
    int line = 0;
    int chapter = 0;
    int temp = 0;
    string words, hold, wordList;
    
    if (file.is_open()) //create word vector
    {
        cout << "Is open.";
        while (! file.eof())
        {
            getline(file, words);   
            if (isChapter(words, book))
            {
                chapter++;
                paragraph = 0;
            }
            else
            {
                if (words.empty())
                {
                    line = 0;
                    paragraph++;
                }
                else
                {
                    line++;
                    for (int i = 0; words[i] != 0; i++)
                    {
                        if (words[i] != ' ')
                        {
                            wordList += words[i];
                        }
                        if (words[i+1] == ' ' || i == words.size()-1)
                        {
                            for (int i = 0; wordList[i-1] != 0; i++)
                            {
                                if (wordList[i] == '.' || wordList[i] == '?' || wordList[i] == '!' || wordList[i] == ','
									|| wordList[i] == ';' || wordList[i] == ':' || wordList[i] == '-' || wordList[i] == '"'
									|| wordList[i] == char(39) || wordList[i] == '_' || wordList[i] == '(' || wordList[i] == ')')
                                {
                                   if (i == 0 || i == wordList.size()-1)
                                   {
                                       wordList.erase(i, i+1);
                                   } 
                                }
                            }
                            wordList = makeLower(wordList);
                            if (book.checkIgnore(wordList) == false)
                            {
                                if (book.getSize() > 0) //check if word has already been found
                                {
                                    temp = book.lookUp(wordList);
                                    if (temp != -1) //word is already listed
                                    {
                                        book.addUse(chapter, paragraph, line, temp);
                                    }
                                    else //word is new 
                                    {
                                        bookWords* addWord = new bookWords(chapter, paragraph, line, wordList);
                                        book.add(addWord);
                                    }
                                }
                                else //adding first word
                                {
                                    bookWords* newWord = new bookWords(chapter, paragraph, line, wordList);
                                    book.add(newWord);
                                }
                            }
                            wordList.clear();
                        }
                    }
                }
            }
        }
        file.close();
    }
    //create ignore vector
    if (fileIgnore.is_open())
    {
        bool empty = true;
        while (! fileIgnore.eof())
        {
            getline(fileIgnore, hold);
            empty = false;
            book.addIgnore(hold);
        }
        if (empty)
        {
            book.addIgnore("VOID");
        }
        fileIgnore.close();
    }
    
    if (fileSyn.is_open())
    {
        while (! fileSyn.eof())
        {
            getline(fileSyn, words);
            bookWords* newWord = new bookWords(chapter, paragraph, line, words);
            book.add(newWord);
        }
        fileSyn.close();
    }

    for (int i = 0; i < book.getSize(); i++)
    {
        cout << "HELP" << endl;
        cout << book.getSynonyms(i) << " " << book.getUse(i) << endl << endl;
    }
    // if (fileResults.is_open())
    // {
    //     cout << "I'm opening the results.";
    //     book.sortingHat();
    //     for (int i = 0; i < book.getSize(); i++)
    //     {
    //         cout << fileResults << book.getSynonyms(i) << " " << book.getUse(i) << endl << endl;
    //     }
    // }
}
/*
    if (words == "") //blankline
    {
        if (!(listOfWords.empty() || listOfWords[listOfWords.size()-1] == ""))
        {
            paragraph++;   
        }  
    }
    else
    {
        line++;
    }
    listOfWords.push_back(words);

    // new line ++line
    // blank line ++paragraph
    //map of strings to index entries (occurences per paragraph)
    */
