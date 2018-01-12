#ifndef MINERS_WIFE_STATES_H
#define MINERS_WIFE_STATES_H

#include"State.h"

class Telegram;
class MinersWife;
//---------------------------------------------------DoHouseWork
class DoHouseWork:public State<MinersWife>{
	DoHouseWork(){}
	DoHouseWork(const DoHouseWork&){}
	DoHouseWork*operator=(const DoHouseWork&){}
public:
	static DoHouseWork*Instance();
	virtual void Enter(MinersWife*pMinersWife);
	virtual void Execute(MinersWife*pMinersWife);
	virtual void Exit(MinersWife*pMinersWife);
	virtual bool OnMessage(MinersWife*pMinersWife,Telegram&telegram);
};
class WatchTV:public State<MinersWife>{
	WatchTV(){}
	WatchTV(const WatchTV&){}
	WatchTV*operator=(const WatchTV&){}
public:
	static WatchTV*Instance();
	virtual void Enter(MinersWife*pMinersWife);
	virtual void Execute(MinersWife*pMinersWife);
	virtual void Exit(MinersWife*pMinersWife);
	virtual bool OnMessage(MinersWife*pMinersWife,Telegram&telegram);
};
class MinersWifeGlobalState:public State<MinersWife>{
	MinersWifeGlobalState(){}
	MinersWifeGlobalState(const MinersWifeGlobalState&){}
	MinersWifeGlobalState*operator=(const MinersWifeGlobalState&){}
public:
	static MinersWifeGlobalState*Instance();	
	virtual void Enter(MinersWife*pMinersWife);
	virtual void Execute(MinersWife*pMinersWife);
	virtual void Exit(MinersWife*pMinersWife);
	virtual bool OnMessage(MinersWife*pMinersWife,Telegram&telegram);
};
#endif//MINERS_WIFE_STATES_H