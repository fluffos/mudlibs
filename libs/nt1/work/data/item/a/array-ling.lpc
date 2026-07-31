// SN:4RRiX5Yo6`B?gKMH
// ITEM Made by player(艾汀:array) /data/item/a/array-ling.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 10 15:26:15 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30m圣火令[2;37;0m", ({ "ling" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：艾汀(array)
");
	set("value", 2100000);
	set("point", 617);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[30m圣火令[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[30m圣火令[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
