#ifndef SRC_WORDNINJA_H
#define SRC_WORDNINJA_H

#include<map>
#include<vector>

class WordNinga
{
public:
    WordNinga();
    ~WordNinga();
    int init(const std::string dictPath);
    int split(const std::string inputText, std::vector<std::string>& result);
private:
inline  bool isDigit(const std::string& str);
private:
    std::map<std::string, float> m_dict;
    int m_wordMaxLen;
};



#endif