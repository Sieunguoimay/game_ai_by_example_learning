#include"Miner.h"

//-----------------------------------------------------------Methods for EnterMindAndDigForNugget
void EnterMineAndDigForNugget::Enter(Miner*miner){
	std::cout<<"\nWalkin' to the gold mine";
}
void EnterMineAndDigForNugget::Execute(Miner*miner){
	std::cout<<"\nAh'm working on the gold mine";
	miner->AddToGoldCarried(1);
	if(miner->PocketsFull()){
		miner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
		return;
	}
	miner->IncreaseFatigue();
	if(miner->Fatigued()){
		miner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
		return;
	}
	miner->IncreaseThirst();
	if(miner->Thirsty()){
		miner->GetFSM()->ChangeState(QuenchThirst::Instance());
		return;
	}
}
void EnterMineAndDigForNugget::Exit(Miner*miner){
	std::cout<<"\nAh'm leavin' the gold mine with mah pockets full o' sweet gold";
}
EnterMineAndDigForNugget*EnterMineAndDigForNugget::Instance(){
	static EnterMineAndDigForNugget instance;
	return &instance;
}

//-------------------------------------------------------------Methods for VisitBankAndDepositGold
void VisitBankAndDepositGold::Enter(Miner*miner){
	std::cout<<"\nAh'm going to Bank";
}
void VisitBankAndDepositGold::Execute(Miner*miner){
	std::cout<<"\nDepositing gold";
	miner->SetGoldCarried(0);
	miner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	if(miner->Fatigued()){
		miner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
		return;
	}
}
void VisitBankAndDepositGold::Exit(Miner*miner){
	std::cout<<"\nMy pocket is empty again";
}
VisitBankAndDepositGold*VisitBankAndDepositGold::Instance(){
	static VisitBankAndDepositGold instance;
	return &instance;
}


//------------------------------------------------------------Methods for GoHomeAndSleepTilRest
void GoHomeAndSleepTilRested::Enter(Miner*miner){
	std::cout<<"\nHoney Ah'm comin home";
}
void GoHomeAndSleepTilRested::Execute(Miner*miner){
	std::cout<<"\nZZZZ...";
	miner->DecreaseFatigue();
	if(miner->Fatigue()==0){
		miner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}
void GoHomeAndSleepTilRested::Exit(Miner*miner){
	std::cout<<"\nGoodbye honey";
}
GoHomeAndSleepTilRested*GoHomeAndSleepTilRested::Instance(){
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

//----------------------------------------------------------Methods For QuenchThirst
void QuenchThirst::Enter(Miner*miner){
	std::cout<<"\nCan I have some Whiskey, Sir";
}
void QuenchThirst::Execute(Miner*miner){
	std::cout<<"\nDinkin' Whiskey. So relaxed";
	miner->BuyAndDrinkWhiskey();
	miner->GetFSM()->ChangeState(EnterMineAndDigForNugget::Instance());
}
void QuenchThirst::Exit(Miner*miner){
	std::cout<<"\nAh'm ok now";
}
QuenchThirst*QuenchThirst::Instance(){
	static QuenchThirst instance;
	return &instance;
}


//-----------------------------------------------------------Methods for MinerGlobalState

void MinerGlobalState::Enter(Miner*miner){

}
void MinerGlobalState::Execute(Miner*miner){

}
void MinerGlobalState::Exit(Miner*miner){

}
MinerGlobalState*MinerGlobalState::Instance(){
	static MinerGlobalState instance;
	return&instance;
}
//thiet ke them mot vai cai khac xem nao
//mot vai cai State khac do tu minh thiet ke
//vi du nhu khi nao ma khat nuoc xem nao
//di den cho mua do uong xong uong OK