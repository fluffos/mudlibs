#include <std.h>;
#include <rest.h>;

inherit WEAPON;

void create()
{
    ::create();

    set("id",({"nunchucks","nunchaku","weapon","flail"}));
    set_name("nunchaku");
    set("short","Nunchaku");
    set("long","The nunchaku has long been used ");
    set_weight(10);
    set_curr_value("gold", 320);
    set_hit( (: this_object(), "weapon_hit" :) );
    set_wc(11);
    set_type("flail");
}

int query_auto_load()
{
    if (this_player()->query_level() > 35 && this_player()->query_guild() ==
      "AoD")
	return 1;
}



