// ITEM Made by player(南巷故人:a304374772_1) /data/item/a/a304374772_1-yzgm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 00:47:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m月之光芒[2;37;0m", ({ "yzgm" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一柄剑。

[1;36m江天一色无纤尘
[1;36m皎皎空中孤月轮
[1;36m江畔何人初见月
[1;36m江月何年初照人[2;37;0m
剑柄上刻着一行小字：南巷故人(a304374772_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "\n[1;36m月光色，女子香\n[1;36m剑断泪，情多长\n[1;36m望明月，心悲凉\n[1;36m千古恨，轮回尝[2;37;0m\n");
	set("unwield_msg", "[1;36m一别星桥夜\n[1;36m三移斗柄春\n[1;36m斜汉晓依依\n[1;36m暗蛰还促机[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
