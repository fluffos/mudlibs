// SN:8R\3?nHd=M08GCj=
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-buxuezi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Nov  1 14:29:55 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("步靴子[2;37;0m", ({ "buxuezi" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
布料的靴子，初级货色。[2;37;0m
靴子缘上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 76);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备步靴子[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了步靴子[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
