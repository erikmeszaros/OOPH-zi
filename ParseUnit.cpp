#include "ParseUnit.h"
#include <fstream>
#include <iostream>



void ParseUnit::parseCSV(const std::string& filename, std::map<std::string,std::vector<std::string>>& data){
    std::ifstream file;
    std::string key,val;
    std::string line="";
    file.open(filename);
    if (!file.is_open()) throw "File not found!";
    if (!getline(file,line)) throw "Empty CSV file!";
    while(std::getline(file,line)){
        parseCSV_line(data,line);
    }
    file.close();
}

void ParseUnit::parseCSV_line(std::map<std::string,std::vector<std::string>>& data,std::string line){
    bool inString=false;
    std::vector<std::string> vec;
    std::string val="";
    for (int i=0;i<line.length();i++){
        if (line[i]=='"'){
            inString=!inString;
        }
        if (line[i]==',' && !inString){
            vec.push_back(val);
            val="";
        }
        else{
            val=val+line[i];
        }
    }
    vec.push_back(val);
    data.insert(std::pair<std::string,std::vector<std::string>>(vec.front(),vec));
}
