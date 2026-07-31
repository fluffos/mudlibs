// he_chang.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("鹤氅", ({ "he chang","chang" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一件道家常见的鹤氅。\n");
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	setup();
}