// shield.c

#include <armor.h>

inherit SHIELD;

void create()
{
	set_name("Å£Æ¤¶Ü", ({ "leather shield", "shield" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "Ãæ");
		set("value", 1000);
		set("armor_prop/armor", 25);
		set("armor_prop/defense", 23);
	}
	setup();
}
