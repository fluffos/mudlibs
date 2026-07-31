// gangdao.c

#include <weapon.h>
inherit BLADE;

void create()
{
	set_name("木刀", ({ "mublade", "mublade" }));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄小木刀，上面刻有一个小小的张字。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回刀鞘。\n");
	}
	init_blade(5);
	setup();
}
