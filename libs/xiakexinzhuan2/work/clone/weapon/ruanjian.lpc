// sword.c 软剑

#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
	set_name(HIW"软剑"NOR, ({ "ruan jian", "jian" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄剑身柔软的精钢剑，不用的时候可以把它盘在腰间。\n");
		set("value", 500);
		set("material", "softsteel");
		set("wield_msg", "$N「唰」的一声从腰中抽出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n盘回腰间。\n");
	}
	init_sword(30);
	setup();
}
