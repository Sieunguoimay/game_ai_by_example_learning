#include"MinersWifeStates.h"
#include"MinersWife.h"

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

//----------------------------------------------------------Methods For MinersWifeGlobalState
void MinersWifeGlobalState::Enter(MinersWife*pMinersWife){

}
void MinersWifeGlobalState::Execute(MinersWife*pMinersWife){

}
void MinersWifeGlobalState::Exit(MinersWife*pMinersWife){

}
MinersWifeGlobalState*MinersWifeGlobalState::Instance(){
	static MinersWifeGlobalState instance;
	return &instance;
}	