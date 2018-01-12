#include"Miner.h"
#include"MinerOwnedStates.h"

Miner::Miner(int id):BaseGameEntity(id),m_iGoldCarried(0),m_iFatigue(0),m_iThirst(0){
	m_pStateMachine = new StateMachine<Miner>(this);

	m_pStateMachine->SetCurrentState(EnterMineAndDigForNugget::Instance());
	m_pStateMachine->SetGlobalState(MinerGlobalState::Instance());
}

Miner::~Miner(){
	delete m_pStateMachine;
}
void Miner::Update(){
	m_pStateMachine->Update();
}

StateMachine<Miner>* Miner::GetFSM()const{
	return m_pStateMachine;
}

