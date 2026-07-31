// SN:03kRiUg886I;X4Bn
// ITEM Made by player(火火:zen) /data/item/z/zen-huo.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 21 03:28:05 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m骷髅指环[2;37;0m", ({ "huo" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;37m这个从一位死去的深山隐者手上摘下的指环，散发着郁郁的光芒[2;37;0m
铁掌缘上刻着一行小字：火火(zen)
");
	set("value", 2100000);
	set("point", 170);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m骷髅指环[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m骷髅指环[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
