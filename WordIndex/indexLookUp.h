#include <iostream>
#include <vector>
#include "word.h"
using namespace std;

class index
{
public:
    index() {};
    ~index() {};
    double getSize() {return allWords.size();}
    string getSynonyms(int x) {return allWords[x]->getSyn();}
    string getUse(int x) {return allWords[x]->render(allChapters);}
    int lookUp(string x)
    {
        for (int i = 0; i < allWords.size(); i++)
        {
            if (allWords[i]->findSyn(x))
            {
                return i;
            }
        }
        return 0;
    }
    void add(bookWords* z) {allWords.push_back(z);}
    void addUse(int chp, int p, int ln, int indice) {allWords[indice]->addOn(chp, p, ln);}
    void addIgnore(string x) {ignoreWords.push_back(x);}
    bool checkIgnore(string z)
    {
        for (int i = 0; i < ignoreWords.size(); i++)
        {
            if (z == ignoreWords[i])
            {
                return true;
            }
        }
        return false;
    }
    string getChapter(int index) {return allChapters[index];}
    void addChapter(string chapter) {allChapters.push_back(chapter);}
    void sortingHat()
    {
        sort(allWords.begin(), allWords.end(), bookWords::nameSort);
    }

private:
    vector<string> allChapters;
    vector<bookWords*> allWords;
    vector<string> ignoreWords;
};
