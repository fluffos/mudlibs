// color_head.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("绣花头巾", ({ "color-headband", "headband" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条绣着大红花朵的头巾，女孩子用来扎头发用。\n");
		set("unit", "条");
		set("value", 800);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 21);
		set("female_only", 1);
	}
	setup();
}

