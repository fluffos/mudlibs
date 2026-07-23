// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
    	set_name("日本刀", ({ "riben dao", "dao", "blade" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄雪亮的日本刀，锋利异常。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」拔出腰间的$n握在手中。\n");
		set("unwield_msg", "$N挽个刀花，将$n插回刀鞘。\n");
	}
	init_blade(40);
	setup();
}
