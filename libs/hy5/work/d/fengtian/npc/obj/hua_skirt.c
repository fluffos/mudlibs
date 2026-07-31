// hua_skirt.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("细花裙", ({ "skirt" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条蓝底上点缀着细花的布裙。\n");
		set("unit", "条");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("female_only", 1);
		set("value",500);
	}
	setup();
}