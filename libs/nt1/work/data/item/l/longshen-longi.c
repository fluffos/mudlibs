// SN:^m`[X8ToVY7YW57m
// ITEM Made by player(南宫天龙:longshen) /data/item/l/longshen-longi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May  3 09:01:59 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m九天[33m翔龙[2;37;0m", ({ "longi" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：南宫天龙(longshen)
");
	set("value", 1500000);
	set("point", 140);
	set("material", "steel");
	set("wear_msg", "[33m$N[33m装备[1;34m九天[33m翔龙[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;34m九天[33m翔龙[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
