// ITEM Made by player(洛竹:wswzly_1) /data/item/w/wswzly_1-luozhu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 18 17:49:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[32m翠竹剑[2;37;0m", ({ "luozhu" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：洛竹(wswzly_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "$N拔下脑后的翠绿发簪随手一抖，化作一柄翠绿色的灵剑[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
