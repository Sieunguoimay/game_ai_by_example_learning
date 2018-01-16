#include"MinersWife.h"
#include"MinersWifeStates.h"
#include"CrudeTimer.h"
#include"MessageDispatcher.h"
void DoHouseWork::Enter(MinersWife*pMinersWife){
	std::cout<<"\nBack to works";
}
void DoHouseWork::Execute(MinersWife*pMinersWife){
	std::cout<<"\nDoing house works...";
	pMinersWife->GetFSM()->ChangeState(WatchTV::Instance());
}
void DoHouseWork::Exit(MinersWife*pMinersWife){
	std::cout<<"\nSo tired. I'm gonna watch TV";
}
bool DoHouseWork::OnMessage(MinersWife*pMinersWife,const Telegram&telegram){
	
	return false;
}
DoHouseWork*DoHouseWork::Instance(){
	static DoHouseWork instance;
	return &instance;
}


//---------------------------------------------------------Methods For WatchTV
void WatchTV::Enter(MinersWife*pMinersWife){
	std::cout<<"\nOpening TV";
}
void WatchTV::Execute(MinersWife*pMinersWife){
	std::cout<<"\nI'm watching a movie";
	pMinersWife->GetFSM()->ChangeState(DoHouseWork::Instance());
}
void WatchTV::Exit(MinersWife*pMinersWife){
	std::cout<<"\nThe movie is over";
}
WatchTV*WatchTV::Instance(){
	static WatchTV instance;
	return &instance;
}
bool WatchTV::OnMessage(MinersWife*pMinersWife,const Telegram&telegram){
	
	return false;
}

//----------------------------------------------------------Methods For MinersWifeGlobalState
void MinersWifeGlobalState::Enter(MinersWife*pMinersWife){

}
void MinersWifeGlobalState::Execute(MinersWife*pMinersWife){

}
void MinersWifeGlobalState::Exit(MinersWife*pMinersWife){

}
bool MinersWifeGlobalState::OnMessage(MinersWife*pMinersWife,const Telegram&telegram){
	switch(telegram.Msg){
		case Msg_HiHoneyImHome:{
			std::cout<<"\nMessage handled by "<<GetNameOfEntity(pMinersWife->ID())<<" at time: "
				<<Clock->GetCurrentTime();
			std::cout<<"\nHi honey Welcome home!";
		}
		case Msg_ByeHoneyImLeaving:{
			std::cout<<"\nMessage handled by "<<GetNameOfEntity(pMinersWife->ID())<<" at time: "
				<<Clock->GetCurrentTime();
			std::cout<<"\nSee you again!";
		}
		return true;
	}	
	return false;
}
MinersWifeGlobalState*MinersWifeGlobalState::Instance(){
	static MinersWifeGlobalState instance;
	return &instance;
}	
