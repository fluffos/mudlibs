//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)

// The condition heal living's hp, by Kyoko@Eastern.Stories (09-19-94)
// This condition can't be removed. It will effect forever.
// Almost rewritten by Annihilator@Eastern.Stories (09-21-94)

#define COND_NAME "_heal_tp"

varargs void apply_effect(object player, int tick, int point);
void remove_effect(object player);

void create()
{
	seteuid(getuid());
}

// This is called in EVERY LIVING in the mud, so do as less thing as can.
void effect(object player)
{
	mixed *cond_data;
	int max, tp;

	// if he has no max_tp, skip entirely.
	max = (int)player->query("max_tp");
	if( undefinedp(max) ) {
		remove_effect(player);
		return;
	}
	if( max < 1 || player->query_temp("stop_heal_hp") ) return;

	cond_data = player->query("conditions/" + COND_NAME);
	if( sizeof(cond_data) < 2 || cond_data[0] < 20 ||
		!intp(cond_data[1]) || cond_data[1]==0 ) {
		apply_effect(player, 30, 10);
		return;
	}

	tp = (int)player->query("talk_points");
	
	if( tp + cond_data[1] < max )
		player->set("talk_points", cond_data[1] + tp );
	else
		player->set("talk_points", max );
}

// This is used to initialize the condition. Will modify it with race stuff
// later. By Annihilator@Eastern.Stories (09-21-94)
varargs void apply_effect(object player, int tick, int point)
{
	// only user need this condition.
	if( !userp(player) ) return;

	if( tick < 20 ) tick = 30;
	if( !point ) point = 10;
	player->set("conditions/" + COND_NAME, ({ tick, point }));
}

// Don't call this unless you want my tp never recover.
void remove_effect(object player)
{
	player->delete("conditions/" + COND_NAME );
}
