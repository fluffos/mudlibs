// SN:nENVd9j^hn[G:6=0
// ITEM Made by player(段浪:smirk) /data/item/s/smirk-naizui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 30 19:38:31 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m奶嘴[2;37;0m", ({ "naizui" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;37m一个可爱的奶嘴。[2;37;0m
指套缘上刻着一行小字：段浪(smirk)
");
	set("value", 2100000);
	set("point", 219);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m奶嘴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m奶嘴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
