// SN:>?oQk^9?61n0Y5@O
// ITEM Made by player(王小石:wxs) /data/item/w/wxs-hxwl.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug 14 10:49:25 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m红[1;33m袖挽[1;31m留[2;37;0m", ({ "hxwl" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
红袖断颈挽留温柔[2;37;0m
铁掌缘上刻着一行小字：王小石(wxs)
");
	set("value", 2100000);
	set("point", 727);
	set("material", "magic stone");
	set("wear_msg", "[1;31m红袖断颈[1;36m挽留温柔[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m红[1;33m袖挽[1;31m留[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
