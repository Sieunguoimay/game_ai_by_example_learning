#include"EntityManger.h"
#include"BaseGameEntity.h"

EntityManger* EntityManger::Instance(){
	static EntityManger instance;
	return instance;
}
void EntityManger::RegisterEntity(BaseGameEntity*NewEntity){
	m_EntityMap.insert(std::make_pair(NewEntity->ID(),NewEntity));
}
BaseGameEntity* EntityManger::GetEntityFromID(int id)const{
	EntityMap::const_iterator ent = m_EntityMap.find(id);
	//assert that the entity is a member of the map
	assert((ent!=m_EntityMap.end())&&"<EntityManger::GetEntityFromID>: invalid ID");
	return ent->second;
}
void EntityManger::RemoveEntity(BaseGameEntity*pEntity){
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}
