// SN:_LCjmo3OKM4jSfha
// ITEM Made by player(段嘎嘎:chucker) /data/item/c/chucker-ggy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jul  9 01:13:09 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("嘎嘎衣[2;37;0m", ({ "ggy" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：段嘎嘎(chucker)
");
	set("value", 2100000);
	set("point", 222);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备嘎嘎衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了嘎嘎衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
