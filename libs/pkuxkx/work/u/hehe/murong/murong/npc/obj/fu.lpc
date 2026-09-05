// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("蒙古兵符", ({ "bingfu","fu" }));
	set_weight(7000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一个可以调动兵马的兵符。\n");
		set("value", 1000);
		set("material", "steel");
	}
	init_blade(20);
	setup();
}
