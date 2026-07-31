

#include <armor.h>

inherit CLOTH;
void create()
{
	set_name("绣花内裤", ({ "color pants","pants" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条女性常用的绣花内裤，散发着一阵奇特的气味。\n");
		set("unit", "条");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

