// SN:O:E5@c>OjWiXP_?c
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-xuantie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May  8 12:59:05 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m玄铁重剑[2;37;0m", ({ "xuantie" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一柄剑。
[1;31m一柄由千古玄铁炼制而成的重剑，没有半死锋芒。[2;37;0m
剑柄上刻着一行小字：慕容新月(xinyue)
");
	set("value", 1500000);
	set("point", 319);
	set("material", "steel");
	set("wield_msg", "[1;31m$N手握玄铁重剑，大喝一声，挚在手中，重剑无锋，大巧不工，一股横挡天下之气概洋溢在眉宇之间。[2;37;0m\n");
	set("unwield_msg", "[1;31m$N反手把玄铁重剑背在肩上，身上那股豪迈之气不见了，双眸锁住了万古的别愁。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
