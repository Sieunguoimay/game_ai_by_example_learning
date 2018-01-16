#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include<map>
#include<cassert>
#include<string>

class BaseGameEntity;
class EntityManager{
	typedef std::map<int,BaseGameEntity*>EntityMap;
	EntityMap m_EntityMap;
	EntityManager(){}

	//make copy constructor and assignment to be private
	EntityManager(const EntityManager&);
	EntityManager*operator=(const EntityManager&);
public:
	//this is singleton
	static EntityManager*Instance();
	void RegisterEntity(BaseGameEntity*NewEntity);
	BaseGameEntity* GetEntityFromID(int id)const;
	void RemoveEntity(BaseGameEntity*pEntity);

};

//to make life easier..
#define EntityMgr EntityManager::Instance()
#endif//ENTITY_MANAGER_H
