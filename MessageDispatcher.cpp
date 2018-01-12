#include"MessageDispatcher.h"
#include"BaseGameEntity.h"
#include"CrudeTimer.h"
#include"EntityManager.h"
#include<iostream>
MessageDispatcher::MessageDispatcher*Instance(){
	static MessageDispatcher instance;
	return &instance;
}
void MessageDispatcher::Discharge(BaseGameEntity*pReceiver,const Telegram&telegram){
	if(!pReceiver->HandleMessage(telegram)){
		std::cout<<"\nMessage not handled";
	}
}
void MessageDispatcher::DispatchMessage(double delay,int sender, int receiver, int msg, void*ExtraInfo){
	BaseGameEntity*pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity*pReceiver = EntityMgr->GetEntityFromID(receiver);
	if(pReceiver == NULL){
		std::cout<<"\nWarnning! No receiver with ID of "<<receiver<<" found";
		return;
	}
	Telegram telegram(0,sender,receiver,msg,ExtraInfo);
	if(delay<=0.0f){
		std::cout<<"\nInstant telegram dispatched at time: "<<Clock->GetCurrentTime()
		<<" by "<<GetNameOfEntity(pSender->ID())<<" for "<<GetNameOfEntity(pReceiver->ID())
		<<". Msg is "<<MsgToStr(msg);
	
		Discharge(pReceiver,telegram);
	}else{
		double CurrentTime = Clock->GetCurrentTime();
		telegram.DispatchTime = CurrentTime+delay;
		PriorityQ.insert(telegram);
		std::cout<<"\nDelayed telegram from "<<GetNameOfEntity(pSender->ID())<<" recorded at time "
		<<Clock->GetCurrentTime()<<" for "<<GetNameOfEntity(pReceiver->ID())
		<<". Msg is "<<MsgToStr(msg);
	}

}

//send out any delayed messages. This method is called each time through the main loop.
void MessageDispatcher::DispatchDelayedMessage(){
	double CurrentTime = Clock->GetCurrentTime();
	while(	!PriorityQ.empty()&&
			PriorityQ.begin()->DispatchTime<CurrentTime&&
			PriorityQ.begin()->DispatchTime>0	)
	{
		const Telegram&telegram = *PriorityQ.begin();
		BaseGameEntity*pReceiver = EntityMgr->GetEntityFromID(telegram.Receiver);
		std::cout<<"\nQueued telegram ready for dispatch: Send to "
			<<GetNameOfEntity(pReceiver->ID())<<". Msg is "<<MsgToStr(msg);

		Discharge(pReceiver,telegram);
		PriorityQ.erase(PriorityQ.begin());
	}
}
