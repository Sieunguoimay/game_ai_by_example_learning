#include"MinersWife.h"
MinersWife::~MinersWife(){
	delete m_pStateMachine;
}

void MinersWife::Update(){
	m_pStateMachine->Update();
}
bool MinersWife::HandleMessage(const Telegram&msg){
	return m_pStateMachine->HandleMessage(msg);
}