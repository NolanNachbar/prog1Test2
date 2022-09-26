#include <iostream>
#include <fstream>
#include "timer.h" 
#include "myList.h"
#include "node.h"


using namespace std;
using std::cout;

//functions
string cleanWord(string wordD);
int skipped = 0;


myList<string> dictionaryList;
myList<string> bookList;


int main()
{

    Timer tim;
    
 
    //reading the dictionary
    int dictionarySize = 0;
    string tmp;
    ifstream dictFile;
    dictFile.open("miniDict.txt");
    
    while(dictFile >> tmp)
    {
        tmp = cleanWord(tmp);
        dictionaryList.insert(tmp);
        dictionarySize++;
    }
    



    
    //starting the time
    tim.Start();
    

    
    //reading the book file and comparing to the dictionary
    string btmp;
    ifstream bookFile;

    bookFile.open("miniBook.txt");
    int misspelled = 0;
    int matchNum = 0;
    int comp;

    while(bookFile >> btmp) 
    {
        btmp = cleanWord(btmp);
        if(isblank(btmp[0]) || isspace(btmp[0]))
        {
            skipped++;
        }
        else
        {
            comp = dictionaryList.find(btmp);
            if(comp == 1)
            {
                matchNum++;
            }
            else if(comp != 1)
            {
                misspelled++;
                bookList.insert(btmp);
            }
        }

    }

    tim.Stop();

    cout << "dictionary Size: " << dictionarySize;
    cout << "\n Done checking and these are the results \n";
    cout << " Finished in time: " << setprecision(2) << tim.Time() << "\n";
    cout << " The number of matches: " << matchNum << "\n";
    cout << " The number of misspelled: " << misspelled << "\n"; 
    bookList.printNumCompares();
    cout << "The number of skipped words: " << skipped;
    
    
    
    
    //writing to the misspelled file
    string tempMiss;
    ofstream missFile;
    missFile.open("misspelled.txt");
    int tracker = 0;
    
    while(tracker < 2)//< misspelled && !bookList.isEmpty())
    {
        tracker++;
        cout << " \nTracker : " << tracker;
        cout << "  misspelled" << misspelled - skipped;
        tempMiss = bookList.frontMod();
        missFile << tempMiss << "\n";
    }
    
    missFile.close();
    
    dictionaryList.~myList();
    bookList.~myList();
    

}

string cleanWord(string word)
{
    string cleanW = "";
    for(int i =0; i< word.size(); i++)
    {
        if(isupper(word[i]))
        {
            word[i] = tolower(word[i]);
        }
        if(isalnum(word[i]))
        {
            cleanW = cleanW + word[i];
        }
        else if(word[i] == '\'')
        {
            cleanW = cleanW + word[i];
        }
    }
    
    //return word;
    return cleanW;
};

