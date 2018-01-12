#include"MinersWife.h"
MinersWife::~MinersWife(){
	delete m_pStateMachine;
}

void MinersWife::Update(){
	m_pStateMachine->Update();
}
