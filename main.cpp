#include <iostream>
#include <map>
#include "Unit.h"
#include <ctime>


void printUnits(const std::map<std::string,std::vector<std::string>>& characters){
    for (auto iterMap : characters){
        for (auto iterVec : iterMap.second){
            std::cout<<iterVec<<"\t";
        }
        std::cout<<std::endl;
    }
}

Hero* choseHero (std::map<std::string,std::vector<std::string>>& characters){
    printUnits(characters);
    std::cout<<std::endl;
    Hero* pplayer=NULL;
    std::map<std::string,std::vector<std::string>> :: iterator it;
    do{
        std::cout<<"Kerem adja meg a valasztott karakter nevet: ";
        std::string chosen;
        std::cin>>chosen;
        it=characters.find(chosen);
        if (it!=characters.end()) {
        pplayer=new Hero (characters[chosen][0],stoi(characters[chosen][1]),stod(characters[chosen][2]),stod(characters[chosen][3]),stod(characters[chosen][4]),stod(characters[chosen][5]),characters[chosen][6]); 
        }
    } while (pplayer== NULL);
    return pplayer;
}

void auto_combat(Unit& unit1, Unit& unit2){
    while (true){
        unit1.attack(unit2);
        if (unit2.getHp()<=0){
            std::cout<<"Winner is: "<<unit1.getName()<< std::endl;
            return;
        }
        unit2.attack(unit1);
         if (unit1.getHp()<=0){
            std::cout<<"Winner is: "<<unit2.getName()<< std::endl;
            return;
        }   
    }
}

void auto_combat(Hero& hero1, Hero& hero2){
    srand(time(0));
    while (true){
        std::cout<<hero1<<std::endl;
        std::cout<<hero2<<std::endl;
        if (rand()%100 < 5 ) hero1.specialAttack(hero2);
        else hero1.attack(hero2);
        std::cout<<hero2<<std::endl;
        if (hero2.getHp()<=0){
            std::cout<<"Winner is: "<<hero1.getName()<< std::endl;
            return;
        }
        if (rand()%100 < 5 ) hero2.specialAttack(hero1);
        else hero2.attack(hero1);
        std::cout<<hero1<<std::endl;
        if (hero1.getHp()<=0){
            std::cout<<"Winner is: "<<hero2.getName()<< std::endl;
            return;
        }

    }

}

int main(){
    std::map<std::string,std::vector<std::string>> characters;
    try{
        ParseUnit::parseCSV("Heroes/heroes.csv",characters);
    }
    catch (const char* msg){
        std::cerr<<msg<<std::endl;
    }
    Hero* pplayer1=choseHero(characters);
    Hero& player1=*pplayer1;
    Hero* pplayer2=choseHero(characters);
    Hero& player2=*pplayer2;
    auto_combat(player1,player2);

    
    return 0;
} 