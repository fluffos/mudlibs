// SN:Fa`:42Kmdk6V=X@=
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-buzhanyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 31 08:16:53 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("布战衣[2;37;0m", ({ "buzhanyi" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
布料的战衣，初级货色。[2;37;0m
战衣缘上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 190);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备布战衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了布战衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
