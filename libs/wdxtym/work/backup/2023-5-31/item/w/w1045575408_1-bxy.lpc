// ITEM Made by player(龙飞辰:w1045575408_1) /data/item/w/w1045575408_1-bxy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 21 05:05:44 2023
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("冰心衣[2;37;0m", ({ "bxy" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：龙飞辰(w1045575408_1)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备冰心衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了冰心衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
