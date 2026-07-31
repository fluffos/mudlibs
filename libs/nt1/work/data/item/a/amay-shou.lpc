// SN:oP0Jj>P2>Pb@k4JN
// ITEM Made by player(无头女尸:amay) /data/item/a/amay-shou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 31 11:45:04 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m寿衣[2;37;0m", ({ "shou" }));
	set_weight(1000);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[37m缠魂丝[2;37;0m炼制而成的一件战衣。
[35m一件破破烂烂的衣服，有着很多恶心的尸虫爬来爬去[2;37;0m
战衣缘上刻着一行小字：无头女尸(amay)
");
	set("value", 800000);
	set("point", 70);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;32m寿衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m寿衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
