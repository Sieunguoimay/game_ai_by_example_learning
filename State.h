#ifndef STATE_H
#define STATE_H
#include<iostream>
//Abstract class
struct Telegram;
template<class entity_type>
class State{
public:
	virtual void Enter(entity_type*) = 0;
	virtual void Execute(entity_type*) = 0;
	virtual void Exit(entity_type*) = 0;
	virtual bool OnMessage(entity_type*,const Telegram&)=0;
};
#endif//STATE_H
