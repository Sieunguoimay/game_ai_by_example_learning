#ifndef MINERS_WIFE_H
#define MINERS_WIFE_H
#include"BaseGameEntity.h"
#include"StateMachine.h"
#include"MinersWifeStates.h"
class MinersWife:public BaseGameEntity{
	StateMachine<MinersWife>*m_pStateMachine;
public:
	MinersWife(int id):BaseGameEntity(id)
	{
		m_pStateMachine = new StateMachine<MinersWife>(this);
		m_pStateMachine->SetGlobalState(MinersWifeGlobalState::Instance());
		m_pStateMachine->SetCurrentState(DoHouseWork::Instance());
	}
	~MinersWife();
	//this must be implemented
	virtual bool HandleMessage(const Telegram&msg);
	//so must this
	virtual void Update();
	
	StateMachine<MinersWife>*GetFSM()const{return m_pStateMachine;}
};
#endif//MINER_WIFE_H
