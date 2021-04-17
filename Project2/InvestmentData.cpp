#include <iostream>
using namespace std;

#include "InvestmentData.h"

void InvestmentData::setInitialInvestment(double t_initialInvestment){
	this->m_initialInvestment = t_initialInvestment;
}

void InvestmentData::setMonthlyDeposit(double t_monthlyDeposit) {
	this->m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentData::setAnnualInterest(double t_annualInterest) {
	this->m_annualInterest = t_annualInterest;
}

void InvestmentData::setNumOfYears(int t_numOfYears) {
	this->m_numOfYears = t_numOfYears;
}


double InvestmentData::calcInterestWithoutDeposits() {
	return ((this->m_totalWithoutDeposits) * ((this->m_annualInterest / 100) / 12));
}


double InvestmentData::calcInterestWithDeposits() {
	return ((this->m_totalWithDeposits) * ((this->m_annualInterest / 100) / 12));
}

void InvestmentData::setTotalWithoutDeposits(double t_amount) {
	this->m_totalWithoutDeposits += t_amount;
}

void InvestmentData::setTotalWithDeposits(double t_amount) {
	this->m_totalWithDeposits += t_amount;
}


double InvestmentData::getTotalWithDeposits() { 
	return this->m_totalWithDeposits; 
}

double InvestmentData::getTotalWithoutDeposits() {
	return this->m_totalWithoutDeposits;
}

