// SN:E]NXFTM\S3idh?==
// ITEM Made by player(爱马德:ilovemud) /data/item/i/ilovemud-ganjiang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 27 06:58:33 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("干将[2;37;0m", ({ "ganjiang" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;36m战国名器[1;31m干将[2;37;0m
剑柄上刻着一行小字：爱马德(ilovemud)
");
	set("value", 2100000);
	set("point", 204);
	set("material", "magic stone");
	set("wield_msg", "突然间整个世界一阵[30m黑暗，一道[1;37m剑光[2;37;0m划过，[1;36m干将剑[2;37;0m出现在$N手中[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
