// SN:GN2R@3VGn=VY3IVb
// ITEM Made by player(蚂蚁:satyr) /data/item/s/satyr-tzst.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Dec  1 05:10:32 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m弹[1;34m指[1;31m神[30m通[2;37;0m", ({ "tzst" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
黄药师送的哦[2;37;0m
指套缘上刻着一行小字：蚂蚁(satyr)
");
	set("value", 2100000);
	set("point", 321);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m弹[1;34m指[1;31m神[30m通[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m弹[1;34m指[1;31m神[30m通[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
