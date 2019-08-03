//
//20190803

#include "wordninja.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>
using namespace std;


WordNinga::WordNinga():m_wordMaxLen(0){}
WordNinga::~WordNinga(){}

inline bool WordNinga::isDigit(const std::string& str)
{
    std::stringstream s;
    s << str;
    double d = 0;
    char c;
    return (s >> d) ? !(s >> c): false;
}

int WordNinga::init(const std::string dictPath)
{
    m_dict.clear();
    //reading dict file
    ifstream infile(dictPath);
    if(!infile.is_open())
    {
        cout<<"dict file not exist"<<endl;
        assert(false);
    }
    string word;
    vector<string> words;
    words.reserve(20000);
    while (!infile.eof())
    {
        getline(infile,word);
        if(!word.size()) continue;
        words.push_back(word);
    }
    int dictSize = words.size();
    cout<<"dictsize:"<<dictSize<<endl;
    for(int i = 0; i < words.size();i++)
    {
        m_dict[words[i]] = log((i + 1) * log(dictSize));
        m_wordMaxLen = std::max(m_wordMaxLen,(int)words[i].length());
    }
    return 0;
}

int WordNinga::split(const std::string inputText, std::vector<std::string>& result)
{
    result.clear();
    if(inputText.empty())return -1;
    string lowerStr = inputText;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), (int (*)(int))tolower);
    
    const int len = lowerStr.size();


    vector<std::pair<float, int>> cost;
    cost.reserve(len + 1);///!!!!
    cost.push_back(make_pair(0, -1));
    string subStr = "";
    float curCost = 0.0;
    for(int i = 1; i < len + 1; i++)
    {
        float minCost = cost[i - 1].first + 9e9;
        int minCostIndex = i - 1;


        for(int j = i - m_wordMaxLen > 0 ? i - m_wordMaxLen : 0; j < i; j++)
        {
            subStr = lowerStr.substr(j, i - j);
            if(m_dict.find(subStr) == m_dict.end())continue;

            curCost = cost[j].first + m_dict.at(subStr);
            if(minCost > curCost)
            {
                minCost = curCost;
                minCostIndex = j;
            }
        }
        cost.push_back(std::make_pair(minCost, minCostIndex));
    }

    int n = len;
    int preIndex;
    while (n > 0)
    {
        preIndex = cost[n].second;
        string insertStr = inputText.substr(preIndex, n - preIndex);
        if(!result.empty() && isDigit(insertStr + result[0]))
        {
            result[0] = insertStr + result[0];
        }
        else
        {
            result.insert(result.begin(), insertStr);
        }
        n = preIndex;
    }

    return 0;
}
