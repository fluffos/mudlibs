// ITEM Made by player(李长夜:aaa12345_1) /data/item/a/aaa12345_1-xxx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 16:37:20 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("诛仙[31m[2;37;0m", ({ "xxx" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一柄剑。
魔道祖师佩剑[2;37;0m
剑柄上刻着一行小字：李长夜(aaa12345_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "剑来[2;37;0m\n");
	set("unwield_msg", "去[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
