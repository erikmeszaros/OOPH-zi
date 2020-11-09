#pragma once
#include <string>
#include "ParseUnit.h"

 class Unit{
	friend class Hero;
	protected:
		const std::string name;
		const std::string quote;
		int hp;
		double min_dps;
		double max_dps;
		double precision;
		

	public:
		Unit(const std::string& name, int hp, double min_dps, double max_dps, double precision, const std::string& quote);	
		std::string getName() const;
		std::string getQuote() const;
		int getHp() const;
		double getMin_dps() const;
		double getMax_dps() const;
		double getPrecision() const;
		void attack(Unit& target);
 };

 class Hero : public Unit{
	private:
		double spec_dps;
		
	public:
		Hero(const std::string& name, int hp, double min_dps, double max_dps, double precision,  double spec_dps ,const std::string& quote);
		double getSpec_dps() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
		void specialAttack(Unit& target);
 };