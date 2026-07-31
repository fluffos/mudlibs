// SN:aYUo^cLBbL21I=ik
// ITEM Made by player(无鸣:min) /data/item/m/min-mstrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov 22 02:14:37 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m无鸣掌[2;37;0m", ({ "mstrike" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;31m一双血红的大手掌[2;37;0m
铁掌缘上刻着一行小字：无鸣(min)
");
	set("value", 2100000);
	set("point", 163);
	set("material", "magic stone");
	set("wear_msg", "[1;31m一双血红的大手掌带着火光从远空罩过来[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m无鸣掌[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
