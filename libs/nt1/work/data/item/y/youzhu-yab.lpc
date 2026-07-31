// SN:oi1m>IE7mY]gA_L9
// ITEM Made by player(浦饭幽助:youzhu) /data/item/y/youzhu-yab.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Nov  1 23:40:16 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m圣灵披风[2;37;0m", ({ "yab" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：浦饭幽助(youzhu)
");
	set("value", 2100000);
	set("point", 400);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m圣灵披风[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m圣灵披风[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
