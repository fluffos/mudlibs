// ITEM Made by player(等等:a15976738848_1) /data/item/a/a15976738848_1-dao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 11 23:52:11 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("元始证道剑[2;37;0m", ({ "dao" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一柄剑。
[37m混沌屯蒙如卵，[37m昏昏默默[1;36m盈空。
[33m浩然太素抱鸿蒙。[33m一气循环凝重。
[2;37;0m
剑柄上刻着一行小字：等等(a15976738848_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "元始之气弥漫，大道内蕴其中。[2;37;0m\n");
	set("unwield_msg", "收！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
