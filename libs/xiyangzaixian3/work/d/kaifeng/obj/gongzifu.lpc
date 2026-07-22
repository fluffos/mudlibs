// gongzifu.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("公子服", ({ "gongzi cloth", "cloth" }));
	set("long", "这是一件由包夫人改做给包平穿的布衣.\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 10000);
		set("armor_prop/armor", 50);
	}
	setup();
}
