#ifndef MINER_H
#define MINER_H
//---------------------------------------------------------
//
//	Name:	Miner.h
//	Desc:	A class defining a goldminer.
//	Author:	Mat Buckland, copied by Vu Duy Du
//
//---------------------------------------------------------
#include"BaseGameEntity.h"
#include"StateMachine.h"
#include"MinerOwnedStates.h"
const int ComfortLevel			= 5;
const int MaxNuggets			= 3;
const int TirednessThreshold	= 5;
const int ThirstLevel			= 3;
class Miner:public BaseGameEntity{
	//an instance of the state machine class
	StateMachine<Miner>*m_pStateMachine;

	int m_iGoldCarried;
	int m_iFatigue;
	int m_iThirst;
public:
	Miner(int id);
	~Miner();

	void Update();
	StateMachine<Miner>* GetFSM()const;


	//----------------------------------------------Accessors
	void AddToGoldCarried(int val){m_iGoldCarried+=val;}
	bool PocketsFull()const{return m_iGoldCarried == MaxNuggets;}
	void SetGoldCarried(int val){m_iGoldCarried = val;}
	int GoldCarried()const{return m_iGoldCarried;}

	bool Fatigued()const{return (m_iFatigue>TirednessThreshold);}
	void DecreaseFatigue(){m_iFatigue--;}	
	void IncreaseFatigue(){m_iFatigue++;}	
	int Fatigue()const{return m_iFatigue;}

	bool Thirsty()const{return m_iThirst>ThirstLevel;}
	void BuyAndDrinkWhiskey(){m_iThirst=0;}
	void IncreaseThirst(){m_iThirst++;}
};
#endif//MINER_H