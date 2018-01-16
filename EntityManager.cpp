#include"EntityManager.h"
#include"BaseGameEntity.h"

EntityManager* EntityManager::Instance(){
	static EntityManager instance;
	return &instance;
}
void EntityManager::RegisterEntity(BaseGameEntity*NewEntity){
	m_EntityMap.insert(std::make_pair(NewEntity->ID(),NewEntity));
}
BaseGameEntity* EntityManager::GetEntityFromID(int id)const{
	EntityMap::const_iterator ent = m_EntityMap.find(id);
	//assert that the entity is a member of the map
	assert((ent!=m_EntityMap.end())&&"<EntityManger::GetEntityFromID>: invalid ID");
	return ent->second;
}
void EntityManager::RemoveEntity(BaseGameEntity*pEntity){
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}
