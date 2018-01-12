#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include<map>
#include<cassert>
#include<string>

class BaseGameEntity;
class EntityManger{
	typedef std::map<int,BaseGameEntity*>EntityMap;
	EntityMap m_EntityMap;
	EntityManger(){}

	//make copy constructor and assignment to be private
	EntityManger(const EntityManger&);
	EntityManger*operator=(const EntityManger&);
public:
	//this is singleton
	static EntityManger*Instance();
	void RegisterEntity(BaseGameEntity*NewEntity);
	BaseGameEntity* GetEntityFromID(int id)const;
	void RemoveEntity(BaseGameEntity*pEntity);

};

//to make life easier..
#define EntityMgr EntityManger::Instance()
#endif//ENTITY_MANAGER_H