//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)
// The condition heal living's health, by Kyoko@Eastern.Stories (09-19-94)

#define COND_NAME   "_heal_body"

varargs void apply_effect(object player);
void effect(object player);
void remove_effect(object player);

// This is the effect of heal up his body. Its data packet is very simple:
// ({ <frequency>, <heal number> })
void effect(object player)
{
	mixed *cond_data;
	int time, max, i, med_res;
	string race;

	if( player->query_temp("stop_heal_body") ) return;

	// if body all right, skip entirely.
	med_res = (int)player->query("medication_resistance");
	if( med_res < 1 ) return;

	cond_data = player->query("conditions/"+COND_NAME);
	if( sizeof(cond_data) < 2 || cond_data[0] < 20 ||
		!intp(cond_data[1]) || cond_data[1]==0 ) {
		apply_effect(player, 30, 3);
		return;
	}

	med_res -= cond_data[1];
	if( med_res < 0 ) med_res = 0;
	player->set("medication_resistance", med_res);
}

varargs void apply_effect(object player, int tick, int point)
{

//	make npc can heal_body, modify by Iris
//					96/1/18
//	if( !userp(player) ) return;
	
	if( tick < 20 ) tick = 30;
	if( !point ) point = 3;
	player->set("conditions/"+COND_NAME, ({ tick, point }));
}

void remove_effect(object player)
{
	player->delete("conditions/"+COND_NAME);
}
