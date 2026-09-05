// junfu.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("清军服", ({ "junfu", "cloth" }));
	set("long", "这是一件有点旧的清朝的官兵服。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 200);
		set("armor_prop/armor", 20);
	}
	setup();
}
