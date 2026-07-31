// SN:8Bo^MURY2bZJEP8X
// ITEM Made by player(杨云:soulking) /data/item/s/soulking-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 13 22:00:51 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("碎心的剑[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
平凡的物件必有不平凡之处[2;37;0m
剑柄上刻着一行小字：杨云(soulking)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "暗淡的悠光闪过你以装备完成[2;37;0m\n");
	set("unwield_msg", "火焰般的白光闪过你以取下装备[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
