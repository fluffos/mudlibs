// SN:EWH6h4baN3FQc2QF
// ITEM Made by player(倚碧鸳:ppbrother) /data/item/p/ppbrother-xajhl.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 24 00:59:54 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m笑傲江湖英雄履[2;37;0m", ({ "xajhl" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：倚碧鸳(ppbrother)
");
	set("value", 2100000);
	set("point", 40);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m笑傲江湖英雄履[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m笑傲江湖英雄履[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
