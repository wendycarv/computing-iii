#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(int argc, char * argv[]) {
    
    string aWord;
    cout << "Please enter a paragraph: ";
    map<string, unsigned>words;
    set<string> commonWords = {"and", "an", "a", "the"};
    
    while (cin >> aWord)
    {
        cout << aWord << endl;
        //keep reading words from the keyboard, until get EOF (press enter and then Ctrl-D/Ctrl-Z)
        //compare p to aWord
        if(commonWords.find(aWord) == commonWords.end())
        {
            if (words.find(aWord) == words.end())
            {
                words[aWord] = 1;
            } else
            {
                words[aWord]++;
            }
        }
    }
    
    for (auto eachWords:words)
    {
        cout << eachWords.first << ": " << eachWords.second << endl;
    }
    return 0;
}
