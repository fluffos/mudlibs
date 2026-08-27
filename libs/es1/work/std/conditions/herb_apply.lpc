//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)

// The condition for herb apply, by Annihilator@Eastern.Stories
// Almost rewritten by Annihilator@Eastern.Stories (09-21-94)

#define COND_NAME "herb_apply"

// Healed every 10 heart beat.
#define DEFAULT_HEAL_TICK 10

void remove_effect(object player);

void effect(object player)
{
	mixed *cond_data;
	int max, hp;

	// if he has no max_hp, skip entirely.
	if( !max = (int)player->query("max_hp") ) return;

	if( player->query_temp("stop_heal_hp") ) return;

	cond_data = player->query("conditions/" + COND_NAME);
	if( sizeof(cond_data) < 3 || !intp(cond_data[1]) ) return;
	
	hp = (int)player->query("hit_points");
	
	if( hp + cond_data[1] < max )
		player->set("hit_points", cond_data[1] + hp );
	else
		player->set("hit_points", max );
	cond_data[2]--;
	if( cond_data[2]<1 ) remove_effect(player);
	else player->set("conditions/" + COND_NAME, cond_data);
}

// This is used to initialize the condition. Will modify it with race stuff
// later. By Annihilator@Eastern.Stories (09-21-94)
void apply_effect(object player, int tick, int point, int count)
{
	if( tick < 1 ) tick = DEFAULT_HEAL_TICK;
	player->set("conditions/" + COND_NAME, ({ tick, point, count }));
}

void remove_effect(object player)
{
	player->delete("conditions/" + COND_NAME );
}
