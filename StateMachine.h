#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H
#include<assert.h>
#include"State.h"
template<class entity_type>
class StateMachine{
private:
	//A pointer tot the agent that owns this instance
	entity_type*m_pOwner;
	State<entity_type>*m_pCurrentState;
	//A record of the last state the agent was in
	State<entity_type>*m_pPreviousState;
	//this state logic is called every time the FSM is updated
	State<entity_type>*m_pGlobalState;

public:
	StateMachine(entity_type*owner)
	:m_pOwner(owner),m_pCurrentState(NULL),m_pPreviousState(NULL),
	m_pGlobalState(NULL)
	{}
	//Use the methods to initialize the FSM
	void SetCurrentState(State<entity_type>*s){m_pCurrentState = s;}
	void SetGlobalState(State<entity_type>*s){m_pGlobalState = s;}
	void SetPreviousState(State<entity_type>*s){m_pPreviousState = s;}

	//Call this to update the FSM
	void Update()const{
		//if a global state exits, call its execute method
		if(m_pGlobalState)m_pGlobalState->Execute(m_pOwner);
		//same for the current state
		if(m_pCurrentState)m_pCurrentState->Execute(m_pOwner);
	}
	bool HandleMessage(const Telegram&msg)const{
		if(m_pCurrentState&&m_pCurrentState->OnMessage(m_pOwner,msg)){
			return true;
		}
		if(m_pGlobalState&&m_pGlobalState->OnMessage(m_pOwner,msg)){
			return true;
		}
		return false;
	}
	//Change to new State
	void ChangeState(State<entity_type>*pNewState){
		assert(pNewState&&"<StateMachine::ChangeState>:trying to change to a null state");

		m_pPreviousState = m_pCurrentState;

		m_pCurrentState->Exit(m_pOwner);
		m_pCurrentState = pNewState;
		m_pCurrentState->Enter(m_pOwner);
	}
	void RevertTotPreviousState(){
		ChangeState(m_pPreviousState);
	}

	//accessors
	State<entity_type>*CurrentState()	const{return m_pCurrentState;}
	State<entity_type>*GlobalState()	const{return m_pGlobalState;}
	State<entity_type>*PreviousState()	const{return m_pPreviousState;}

	//returns true if the current state's type is equal to the type of the class passed as a parameter
	bool isInState(const State<entity_type>*st)const{
		return (m_pCurrentState==st);
	}
};
#endif//STATE_MACHINE_H