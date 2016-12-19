#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class bookWords
{
public:
    bookWords(int chp, int p, int ln, string entry) {synonyms.push_back(entry); addOn(chp, p, ln);}
    ~bookWords();
    word(string ln)
    {
        string nextWord;
        for (int i = 0; ln[i] != 0; i++)
        {
            if (ln[i] != ' ')
            {
                nextWord += ln[i];
            }
            if (ln[i+1] == ' ' || i == ln.size()-1)
            {
                synonyms.push_back(nextWord);
                nextWord.clear();
            }
        }
    }
    bool findSyn(string z)
    {
        for (int i = 0; i < synonyms.size(); i++)
        {
            if (synonyms[i] == z)
            {
                return true;
            }
        }
        return false;
    }
    void addOn(int chp, int p, int ln)
    {
        data* newUse = new data;
        newUse->chapter = chp;
        newUse->paragraph = p;
        newUse->line = ln;
        listing.push_back(newUse);
    }
    string getSyn() {return synonyms[0];}
    static bool nameSort(bookWords* w1, bookWords* w2)
    {
        string w1Syn = w1->getSyn();
        string w2Syn = w2->getSyn();
        return (w1Syn < w2Syn);
    }
    string render(vector<string> &z)
    {
        string output;
        if (listing.size()>1)
        {
            for (int i = 0; i < listing.size()-1; i++)
            {
                if (listing[i]->chapter == listing[i+1]->chapter && listing[i]->paragraph == listing[i+1]->paragraph)
                {
                    listing.erase(listing.begin()+i+1);
                    i--;
                }
            }
        }
        xy* newXY = new xy;
        newXY->index = listing[0]->chapter;
        newXY->uses = 0;
        temp.push_back(newXY);
        bool present = false;
        for (int i = 0; i < listing.size(); i++)
        {
            for (int z = 0; z < temp.size(); z++)
            {
                if (listing[i]->chapter == temp[z]->index)
                {
                    temp[z]->uses++;
                    present = true;
                }
                else if (z == temp.size()-1 && present == false)
                {
                    xy* newXY = new xy;
                    newXY->index = listing[i]->chapter;
                    newXY->uses = 1;
                    temp.push_back(newXY);
                }
            }
            present = false;
        }
        int countComma = 0;
        std::sort(temp.begin(), temp.end(), xy::tempSort);
        ostringstream out;
        for (int i = 0; i < temp.size(); i++)
        {
            countComma = 0;
            for (int j = 0; j < listing.size(); j++)
            {
                if (temp[i]->index == listing[j]->chapter)
                {
                    countComma++;
                    output += z[temp[i]->index-1];
                    output += ":P";
                    out << listing[j]->paragraph;
                    output += out.str();
                    output += "L";
                    out.str("");
                    out << listing[j]->line;
                    output += out.str();
                    out.str("");
                    if (i < temp.size()-1)
                    {
                        output += ", ";
                    }
                    else if (temp[i]->uses != countComma)
                    {
                        output += ", ";
                    }
                }
            }
        }
        return output;
    }

private:
    struct data
    {
        int chapter;// = 0;
        int paragraph;// = 0;
        int line;// = 0;
        data() : chapter(0), paragraph(0), line(0)
        {}
    };
    struct xy
    {
        int index;// = 0;
        int uses;// = 0;
        static bool tempSort(xy* xy1, xy* xy2)
        {
            int pair1 = xy1->uses;
            int pair2 = xy2->uses;
            return (pair1 > pair2);
        }
        xy() : index(0), uses(0)
        {}
    };
    vector<xy*> temp;
    vector<data*> listing;
    vector<string> synonyms;
    
};

