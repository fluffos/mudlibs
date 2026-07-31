// ITEM Made by player(夜长歌:s7787888_1) /data/item/s/s7787888_1-jshj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Mar 22 23:13:21 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("绝世好剑[2;37;0m", ({ "jshj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;33m传奇[35m灵石[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：夜长歌(s7787888_1)
");
	set("value", 12100000);
	set("point", 1320);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
