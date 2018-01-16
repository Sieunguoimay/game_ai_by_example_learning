#ifndef MESSAGE_DISPATCHER_H
#define MESSAGE_DISPATCHER_H
#include<set>
#include"Telegram.h"

class BaseGameEntity;
const double SEND_MSG_IMMEDIATELY = 0.0;
const int NO_ADDITIONAL_INFO = 0;

//to make life easier..
#define Dispatch MessageDispatcher::Instance()

class MessageDispatcher{
	//Messages are sorted by their dispatch time
	std::set<Telegram> PriorityQ;
	void Discharge(BaseGameEntity*pReceiver, const Telegram&msg);

	MessageDispatcher(){}
	//copy constructor and assignment should be private
	MessageDispatcher(const MessageDispatcher&);
	MessageDispatcher*operator=(const MessageDispatcher&);
public:
	static MessageDispatcher*Instance();
	void DispatchMessage(double delay,int sender, int receiver, int msg, void*ExtraInfo);
	
	//send out any delayed messages. This method is called each time through the main loop.
	void DispatchDelayedMessage();
};
#endif//MESSAGE_DISPATCHER_H
