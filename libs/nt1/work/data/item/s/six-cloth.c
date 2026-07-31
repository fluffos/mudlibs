// SN:c?C7fomcjNUcN^6c
// ITEM Made by player(渡段:six) /data/item/s/six-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jan  1 22:33:51 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m天皇衣[2;37;0m", ({ "cloth" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;33m天皇圣甲的一部分[2;37;0m
战衣缘上刻着一行小字：渡段(six)
");
	set("value", 2100000);
	set("point", 200);
	set("material", "silk");
	set("wear_msg", "[1;33m穿上天皇衣[2;37;0m\n");
	set("remove_msg", "[1;33m脱下天皇衣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
