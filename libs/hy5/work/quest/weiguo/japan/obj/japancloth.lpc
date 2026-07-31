// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("武士服", ({ "japancloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 0);
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}
