#ifndef MINER_OWNED_STATES_H
#define MINER_OWNED_STATES_H

#include"State.h"
class Miner;

class EnterMineAndDigForNugget:public State<Miner>{
	EnterMineAndDigForNugget(){}

	//copy constructor and assignment should be private
	EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);
	EnterMineAndDigForNugget& operator=(const EnterMineAndDigForNugget&);
public:

	virtual void Enter(Miner*miner);
	virtual void Execute(Miner*miner);
	virtual void Exit(Miner*miner);
	//this is a singleton
	static EnterMineAndDigForNugget*Instance();
};

class VisitBankAndDepositGold:public State<Miner>{
	VisitBankAndDepositGold(){}

	VisitBankAndDepositGold(const VisitBankAndDepositGold&){}
	VisitBankAndDepositGold*operator=(const VisitBankAndDepositGold&){}
public:
	virtual void Enter(Miner*miner);
	virtual void Execute(Miner*miner);
	virtual void Exit(Miner*miner);
	static VisitBankAndDepositGold*Instance();
};


class GoHomeAndSleepTilRested:public State<Miner>{
	GoHomeAndSleepTilRested(){}
	GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&){}
	GoHomeAndSleepTilRested*operator=(const GoHomeAndSleepTilRested&){}
public:
	virtual void Enter(Miner*miner);
	virtual void Execute(Miner*miner);
	virtual void Exit(Miner*miner);
	static GoHomeAndSleepTilRested*Instance();
};
class QuenchThirst:public State<Miner>{
	QuenchThirst(){}
	QuenchThirst(const QuenchThirst&){}
	QuenchThirst*operator=(const QuenchThirst&){}
public:
	virtual void Enter(Miner*miner);
	virtual void Execute(Miner*miner);
	virtual void Exit(Miner*miner);
	static QuenchThirst*Instance();	
};
class MinerGlobalState:public State<Miner>{
	MinerGlobalState(){}
	MinerGlobalState(const MinerGlobalState&){}
	MinerGlobalState*operator=(const MinerGlobalState&){}

public://cai quai gi dand dien ra o day vay, mot dua con gai
	//di vao xong ngoi truoc mat thoi ma lam gi ma cang vay
	//can ban cha hieu sao bon an nay cu thich nhin vao mat nguoi khac
	//nguoi ma minh khong quen
	//-thi cung giong nhu minh cu nhin vao mat may dua khac khi minh noi chuyen cac thu
	//co ma day nguoi khong quen minh co them nhin dau..
	//-thi cung tuy nguoi thoi
	void Enter(Miner*miner);
	void Execute(Miner*miner);
	void Exit(Miner*miner);
	static MinerGlobalState* Instance();
};

#endif//MINER_OWNED_STATES_H
