
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name("紫金甲", ({ "hunyuan jia", "jia" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "gold");
		set("unit", "件");
		set("value", 20000);
		set("armor_prop/armor", 80);
		set("armor_prop/dodge", 11);
		set("armor_prop/defense", 20);
	}
	setup();
}
