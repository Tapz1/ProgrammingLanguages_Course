#pragma once
#ifndef PROJECT2_USERDATACALCULATIONS_H_
#define PROJECT2_USERDATACALCULATIONS_H_
#endif // !PROJECT2_USERDATACALCULATIONS_H_


#include "InvestmentData.h"

class UserDataCalculations {

	public: 
		void dataWithoutDeposits(InvestmentData t_userInvestment);
		void dataWithDeposits(InvestmentData t_userInvestment);

};