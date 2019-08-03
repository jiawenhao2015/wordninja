#include<iostream>
#include "wordninja.h"


using namespace std;

int main()
{
    
    WordNinga *pWordNinga = new WordNinga();
    pWordNinga->init("/Users/jiawenhao/gitcode/wordninja/wordninja_words.txt");

    string inputText = "wethepeopleoftheunitedstatesinordertoformamoreperfectunionestablishjusticeinsuredomestictranquilityprovideforthecommondefencepromotethegeneralwelfareandsecuretheblessingsoflibertytoourselvesandourposteritydoordainandestablishthisconstitutionfortheunitedstatesofamerica";
    //string inputText = "readinginbed";
    cout << inputText<<endl;
    vector<string> result;

   
    pWordNinga->split(inputText, result);

    cout<<"result:"<<endl;
    for(auto str : result)
    {
        cout<< str<<"   ";
    }
    cout<<endl;

    delete pWordNinga;
    return 0;
}