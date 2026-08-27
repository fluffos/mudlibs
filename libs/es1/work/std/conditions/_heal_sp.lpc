//#pragma save_binary

// This is a condition object
// A player may have more than one conditions (usually bad condition) that
// take effects with a certain frequency. Thus condition WILL BE SAVED in
// save files and can only be solved by calling the function "remove_effect"
// defined in this object. The function "effect" is called in a certain
// frequency from the heart_beat ( heal_up() in /std/body/attack.c )
// Created by Annihilator@Eastern.Stories (12-26-93)
// The condition heal living's sp, by Kyoko@Eastern.Stories (09-19-94)

#define COND_NAME "_heal_sp"

void remove_effect(object player);
varargs void apply_effect(object player);

void create()
{
	seteuid(getuid());
}

// This is called in EVERY LIVING in the mud, so do as less thing as can.
void effect(object player)
{
	mixed *cond_data;
	int max, sp;

	// check max first, if undefined then remove this condition.
	// if max < 1 then skip its effect.
	max = (int)player->query("max_sp");
	if( undefinedp(max) ) {
		remove_effect(player);
		return;
	}
	if( max < 1 || player->query_temp("stop_heal_sp") ) return;

	// check cond_data second, if tick error(<1) then reset condition.
	cond_data = player->query("conditions/" + COND_NAME);
	if( sizeof(cond_data) < 2 || cond_data[0] < 1 ||
		!intp(cond_data[1]) || cond_data[1]==0 ) {
		apply_effect(player, 10, 1);
		return;
	}

	sp = (int)player->query("spell_points");
	if( sp + cond_data[1] < max )
		player->set("spell_points", cond_data[1] + sp );
	else
		player->set("spell_points", max );
}

void apply_effect(object player, int tick, int point)
{
	if( tick < 1 ) tick = 10;
	if( !point ) point = 1;
	player->set("conditions/" + COND_NAME, ({ tick, point }));
}

void remove_effect(object player)
{
	player->delete("conditions/" + COND_NAME );
}
