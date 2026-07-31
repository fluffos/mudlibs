// SN:2_i@?2CicdG;;McU
// ITEM Made by player(明慕:gege) /data/item/g/gege-gjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Nov 20 22:26:06 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m慕容一剑[2;37;0m", ({ "gjian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m一把饮血的真红宝剑[2;37;0m
剑柄上刻着一行小字：明慕(gege)
");
	set("value", 2100000);
	set("point", 207);
	set("material", "magic stone");
	set("wield_msg", "[1;31m一道血红之光闪入你手中[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
