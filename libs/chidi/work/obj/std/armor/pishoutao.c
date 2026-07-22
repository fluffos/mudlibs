// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("皮手套",({"pi shoutao","pishoutao","shoutao"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","双");
		set("material","pi");
		set("long", "这是一双牛皮制成的手套，用来保护双手。\n");
		set("armor_prop/armor",5);
		set("value",500);
	}
	setup();
}
