
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("绣花内裤", ({ "color-pants", "pants" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条小得不能再小的粉红色绣花三角内裤，闻起来还有一股淡香。\n");
		set("unit", "条");
		set("value", 1000);
		set("material", "cloth");
		set("armor_prop/armor", 11);
		set("armor_prop/personality", 13);
		set("female_only", 1);
	}
	setup();
}

