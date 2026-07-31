// SN::W[c<@0Xcb8R[nV:
// ITEM Made by player(浦饭幽助:youzhu) /data/item/y/youzhu-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep  8 00:35:25 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m审判之剑[2;37;0m", ({ "jian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
这是[1;31m造物神[2;37;0m的配剑，用来审判犯了大罪大恶的生命。[2;37;0m
剑柄上刻着一行小字：浦饭幽助(youzhu)
");
	set("value", 2100000);
	set("point", 215);
	set("material", "magic stone");
	set("wield_msg", "[1;32m只见一道耀眼的白光闪过，[1;37m审判之剑[1;32m已经出现在$N的手中。[2;37;0m\n");
	set("unwield_msg", "[1;32m只听一声龙吟，[1;37m审判之剑[1;32m已经消失地无影无踪。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
