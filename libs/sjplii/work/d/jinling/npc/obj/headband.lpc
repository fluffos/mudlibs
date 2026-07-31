// color_head.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("青布头巾", ({ "headband" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一块普通的青布头巾。\n");
		set("unit", "块");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 1);
//		set("armor_prop/personality", 0);
//		set("female_only", 1);
	}
	setup();
}

