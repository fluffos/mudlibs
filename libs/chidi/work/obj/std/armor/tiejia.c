// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("铁甲",({"tie jia","tiejia","jia"}));
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material","tie");
		set("oldsix/max_damage",30);
		set("oldsix/protect",4);
		set("long", "这是一件精铁制成的甲胄，用来保护上半身。\n");
		set("armor_prop/armor",20);
		set("value",6000);
	}
	setup();
}
