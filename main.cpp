#include<iostream>
#include<vector>
#include"Miner.h"
#include"MinersWife.h"
#include"EntityManager.h"
int main(){
	std::cout<<"hello Programming Game AI by Example\n";

	std::vector<BaseGameEntity*>GameEntities;
	Miner*Bob = new Miner(ent_Miner_Bob);
	MinersWife*Wife = new MinersWife(ent_Miners_Wife);

	EntityMgr->RegisterEntity(Bob);
	EntityMgr->RegisterEntity(Wife);

	GameEntities.push_back(Bob);
	GameEntities.push_back(Wife);
		//main loop with 30 loops
	for(int i = 0; i<20; i++){
		for(auto&entity:GameEntities)
			entity->Update();
		std::cout<<"\n";
	}
		for(auto&entity:GameEntities)
			delete entity;
	return 0;
}
