// SN:2`KgT@QW3=MY?i8L
// ITEM Made by player(云破月:live) /data/item/l/live-lye.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 24 00:28:32 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m流锦[2;37;0m", ({ "lye" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：云破月(live)
");
	set("value", 2100000);
	set("point", 354);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;35m流锦[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;35m流锦[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
