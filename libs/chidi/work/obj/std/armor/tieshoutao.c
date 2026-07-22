// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("铁手套",({"tie shoutao","tieshoutao","shoutao"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","双");
		set("oldsix/max_damage",30);
		set("oldsix/protect",4);
		set("material","tie");
		set("long", "这是一双精铁制成的手套，用来保护双手。\n");
		set("armor_prop/armor",10);
		set("value",2000);
	}
	setup();
}
