// SN:WOm_;Vc`Y1NM;ZR<
// ITEM Made by player(武林争帝:wlzbiiii) /data/item/w/wlzbiiii-swordb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Nov 25 23:46:24 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m裁决之剑[2;37;0m", ({ "swordb" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m裁决之剑[2;37;0m
剑柄上刻着一行小字：武林争帝(wlzbiiii)
");
	set("value", 2100000);
	set("point", 389);
	set("material", "magic stone");
	set("wield_msg", "[1;31m$N[35m拔出了[1;37m裁决之剑[2;37;0m\n");
	set("unwield_msg", "[1;31m$N[35m收回了[1;37m裁决之剑[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
