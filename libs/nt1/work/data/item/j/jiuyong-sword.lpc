// SN:M87DgXPBNGF_8QmD
// ITEM Made by player(慕容复燕:jiuyong) /data/item/j/jiuyong-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 18 12:39:05 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m紫徽剑[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[35m这是一把泛这紫色光芒的神剑，传说每当天空中紫徽星出现神剑会发挥出无尽的神威。[2;37;0m
剑柄上刻着一行小字：慕容复燕(jiuyong)
");
	set("value", 2100000);
	set("point", 654);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
