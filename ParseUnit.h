#pragma once
#include <string>
#include <map>
#include <vector>

//template  <class T>;  
class ParseUnit{

    public:
    static void parseCSV(const std::string& filename,std::map<std::string,std::vector<std::string>>& data);
    static void parseCSV_line(std::map<std::string,std::vector<std::string>>& data ,std::string line);
};