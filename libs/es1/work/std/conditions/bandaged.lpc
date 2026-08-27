//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)

// The condition for bandaged, by Kyoko@Eastern.Stories

#define COND_NAME "bandaged"

// Healed every 10 heart beat.
#define DEFAULT_HEAL_TICK 10

void remove_effect(object player);

void effect(object player)
{
	mixed *cond_data;
	int max;

	// if not bandaged now, remove effect.
	if( !player->query_temp("bandaged") ) {
		remove_effect(player);
		return;
	}
	
	// if he has no max_hp, skip entirely.
	if( !max = (int)player->query("max_hp") ) return;

	if( player->query_temp("stop_heal_hp") ) return;

	cond_data = player->query("conditions/" + COND_NAME);
	if( sizeof(cond_data) < 2 || !intp(cond_data[1]) ) return;

	if( (int)player->query("hit_points") < max )
		player->add("hit_points", 1);
}

void apply_effect(object player, int tick)
{
	if( tick < 1 ) tick = DEFAULT_HEAL_TICK;
	player->set("conditions/" + COND_NAME, ({ tick, 1, }));
}

void remove_effect(object player)
{
	player->delete("conditions/" + COND_NAME );
}
