// jindi.c 金笛
// by hubo  2008/5/18

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIY"金笛"NOR, ({ "jin di", "di" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把纯金打制的笛子，既可以做乐器，又可做武器。\n");
		set("value", 100000);
		set("material", "gold");
		set("wield_msg", "$N「唰」的一声抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
	init_sword(100);
	setup();
}
