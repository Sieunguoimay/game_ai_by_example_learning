#ifndef TELEGRAM_H
#define TELEGRAM_H
//----------------------------------------------------------------------------------------
//
//	Name:	Telegram.h
//
//	Desc:	This defines a telegram which records infomation required to dispatch messages.
//			Messages are used by game agents to communicate with each other.
//
//	Author:	Mat Buckland - copied by Vu Duy Du
//
//-----------------------------------------------------------------------------------------
#include<iostream>
#include<math.h>
#include <string>
enum message_type
{
  Msg_HiHoneyImHome,
  Msg_StewReady,
};


inline std::string MsgToStr(int msg)
{
  switch (msg)
  {
  case Msg_HiHoneyImHome:
    
    return "HiHoneyImHome"; 

  case Msg_StewReady:
    
    return "StewReady";

  default:

    return "Not recognized!";
  }
}

struct Telegram{
	//These are entity IDs, all enumerated in the file "BaseGameEntity.h" 
	int Sender;
	int Receiver;
	//The messages are enumerated in the file "MessagesType.h"
	int Msg;
	double DispatchTime;
	void*ExtraInfo;
	Telegram():DispatchTime(-1),Sender(-1),
				Receiver(-1),Msg(-1)
	{}
	Telegram(double time,int sender, int receiver, int msg, void*info = NULL):
		DispatchTime(time),Sender(sender),Receiver(receiver),Msg(msg),ExtraInfo(info)
	{}

};

inline bool operator==(const Telegram&t1, const Telegram&t2){
	return (fabs(t1.DispatchTime-t2.DispatchTime)<SmallestDelay)&&
			(t1.Sender == t2.Sender)&&
			(t1.Receiver == t2.Receiver)&&
			(t1.Msg == t2.Msg);
}
inline bool operator<(const Telegram&t1,const Telegram&t2){
	if(t1==t2)
		return false;
	return t1.DispatchTime<t2.DispatchTime;
}
inline std::ostream&operator<<(std::ostream&os,const Telegram&t){
	os<<"time: "<<t.DispatchTime<<" Sender: "<<t.Sender
		<<" Receiver: "<<t.Receiver
		<<" Msg: "<<t.Msg;
	return os;
}

//new trick of C++
template<class T>
inline T DereferenceToType(void*p){
	return *(T*)(p);
}
#endif//TELEGRAM_H