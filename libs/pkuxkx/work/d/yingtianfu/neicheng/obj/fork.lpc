#include <weapon.h>
inherit FORK;

void create()
{
	set_name("钢叉", ({ "gang cha", "cha","fork" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄大明制式的钢叉，高级武将方可使用。\n");
		set("value", 0);
		set("material", "steel");
		set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
		set("no_drop",1);
		set("no_give",1);
		set("no_get","大明的制式钢叉，捡了要杀头的。\n");
	}
	init_fork(100+random(25));
	setup();
}
