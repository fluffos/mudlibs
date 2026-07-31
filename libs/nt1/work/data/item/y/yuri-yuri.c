// SN:@_f<4TAeObIN`ULg
// ITEM Made by player(天天:yuri) /data/item/y/yuri-yuri.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 20 09:42:40 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m辟[1;32m邪[1;37m剑[2;37;0m", ({ "yuri" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m一把[1;32m锋利的[1;31m辟[1;32m邪[1;37m剑[2;37;0m
它在阳光下闪闪发光[2;37;0m
剑柄上刻着一行小字：天天(yuri)
");
	set("value", 2100000);
	set("point", 209);
	set("material", "magic stone");
	set("wield_msg", "[1;37m$N伸手一抖，抽出一把杀人的长剑[2;37;0m\n");
	set("unwield_msg", "[1;31m$N随手一挥，[1;33m$n已入鞘内[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
