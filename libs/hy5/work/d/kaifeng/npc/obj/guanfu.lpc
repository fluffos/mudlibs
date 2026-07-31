// guanfu.c
// LOTS 1998/10/17

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("官服", ({ "guan fu", "cloth", "fu" }));
	set("long", "这是钦差大人的专用官服,是当年皇上亲赐的一品蟒龙袍.\n");
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 2000);
		set("armor_prop/armor", 200);
	}
	setup();
}
