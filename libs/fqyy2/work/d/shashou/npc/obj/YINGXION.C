// yingxion.c 英雄剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
	set_name("英雄剑", ({ "yingx sword", "sword" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这把剑外观十分平凡，剑鞘古拙无光，却流露着一股异常感觉，
		使人一望就知道是一柄绝世神剑。\n");
		set("value", 1000000);
		set("material", "steel");
		set("no_drop", "这样东西不能离开你。\n");
		set("no_get", "这样东西不能离开那儿。\n");
		set("wield_msg", HIY "只听「铮」的一声，英雄剑脱鞘飞出，自行跃入$N掌中。
瞬时天际间风云变色，电闪雷鸣，弥漫着一片无边杀意。\n" NOR);
		set("unwield_msg", HIY "英雄剑自$N掌中飞起，在半空中一转，「唰」地跃入刀鞘。\n" NOR);
	}
	init_sword(1000);
	setup();
}
