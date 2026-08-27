//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Iris@Eastern.Stories (12-19-95)

#define COND_NAME "_heal_ap"

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
	int max, ap;

	// if he has no max_hp, skip entirely.
	max = (int)player->query("max_ap");
	if( undefinedp(max) ) {
		remove_effect(player);
		return;
	}
	if( max < 1 ) return;

	cond_data = player->query("conditions/" + COND_NAME);
	if( sizeof(cond_data) < 2 || cond_data[0] < 1 ||
		!intp(cond_data[1]) || cond_data[1]==0 ) {
		apply_effect(player, 30, 300);
		return;
	}

	ap = (int)player->query("action_points");
	
	if( ap + cond_data[1] < max )
		player->set("action_points", cond_data[1] + ap );
	else
		player->set("action_points", max );
}

// This is used to initialize the condition.
varargs void apply_effect(object player, int tick, int point)
{
	if( tick < 1 ) tick = 10;
	if( !point ) point = 300;
	player->set("conditions/" + COND_NAME, ({ tick, point }));
}

// Don't call this unless you want my hp never recover.
void remove_effect(object player)
{
	player->delete("conditions/" + COND_NAME );
}
