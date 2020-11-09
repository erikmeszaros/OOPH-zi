#include "Unit.h"
#include <iostream>
#include <random>


Unit::Unit(const std::string& name, int hp, double min_dps, double max_dps, double precision, const std::string& quote) : name(name), hp(hp), min_dps(min_dps), max_dps(max_dps), precision(precision) {};
Hero::Hero(const std::string& name, int hp, double min_dps, double max_dps, double precision, double spec_dps, const std::string& quote) : Unit(name,hp,min_dps,max_dps,precision,quote), spec_dps(spec_dps){};

std::string Unit::getName() const{
    return name;
}
std::string Unit::getQuote() const{
    return quote;
}
int Unit::getHp() const{
    return hp;
}
double Unit::getMin_dps() const{
    return min_dps;
}
double Unit::getMax_dps() const{
    return max_dps;
}
double Unit::getPrecision() const{
    return precision;
}
double Hero::getSpec_dps() const{
    return spec_dps;
}

std::ostream& operator<<(std::ostream& os, const Hero& hero){
	os<< hero.getName() << "\t" << hero.getHp() << std::endl;
	return os;
} 

void Unit::attack(Unit& target){
    std::random_device rd;
    std::mt19937 gen(rd()); //átnézni hogyan működik
    std::uniform_real_distribution<> dist (min_dps,max_dps);
    int dmg_thist_turn=std::round(dist(gen));
    target.hp-=dmg_thist_turn;
    if (target.hp<0) target.hp=0;
}

void Hero::specialAttack(Unit& target) {
    target.hp-=spec_dps;
    if (target.hp<0) target.hp=0;
}