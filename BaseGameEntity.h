#ifndef BASE_GAME_ENTITY_H
#define BASE_GAME_ENTITY_H
#include<string>
enum entity_type{
	ent_Miner_Bob,
	ent_Miners_Wife
};
inline std::string GetNameOfEntity(int n)
{
  switch(n)
  {
  case ent_Miner_Bob:

    return "Miner Bob";

  case ent_Miners_Wife:
    
    return "Elsa"; 

  default:

    return "UNKNOWN!";
  }
}
#include"Telegram.h"
class BaseGameEntity{
	int m_ID;
	static int m_iNextValidID;
	void SetID(int val){
		m_ID = val;
	}
public:
	BaseGameEntity(int id){
		SetID(id);
	}
	virtual ~BaseGameEntity(){}

	//All entitis must implement an update function
	virtual void Update()=0;
	//All entities can communicate using message. They are sent
	//using MessageDispatcher singleton class
	virtual bool HandleMessage(const Telegram&msg)=0;

	int ID()const{return m_ID;}
};
#endif//BASE_GAME_ENTITY_H
