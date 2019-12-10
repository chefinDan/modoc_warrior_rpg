/*******************************************************************************
* Author: Daniel Green
* Date: 8/5/2018
* Description: Die class definition and implementation file. A a pointer to
* a dice object is held in Character.hpp. An object of this class is created
* each time a character either attacks or defends.   
*******************************************************************************/

#include <cstdlib>
#include <ctime>
#include <iostream>

#ifndef DICE_HPP
#define DICE_HPP
class Die{
private:
	int N;
	int wins;
	int result;

public:
	inline Die(int n){
		this->result = 0;
		this->wins = 0;
		this->N = n;
	}
	inline ~Die(){}

	inline void roll(){this->result = (std::rand() %this->N) +1;}

	inline int getResult() {return this->result;}
	inline void setResult(int result) {this->result = result;}

	inline int& getN() {return this->N;}
	inline void setN(int n) {this->N=n;}

	inline int& getWins() {return this->wins;}
	inline void setWins(int w) {this->wins = w;}
};

// class D6 : public Die{
// private:
// public:
// 	D6(){
// 		this->N = 6;
// 	}
// };
//
// class D10 : public Die{
// private:
// public:
// 	D10(){
// 		this->N = 10;
// 	}
// };
//
// class D12 : public Die{
// private:
// public:
// 	D12(){
// 		this->N = 12;
// 	}
// };
#endif
