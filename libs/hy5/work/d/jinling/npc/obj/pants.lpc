
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("纯棉内裤", ({ "pants" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条男性常用的黑色内裤。\n");
		set("unit", "条");
		set("value", 0);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 0);
	}
	setup();
}

