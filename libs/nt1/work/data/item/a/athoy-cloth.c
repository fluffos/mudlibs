// SN:DXD6fWj3oY\H\c[L
// ITEM Made by player(神游:athoy) /data/item/a/athoy-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jun 30 17:10:14 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m破云衣[2;37;0m", ({ "cloth" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;37m一件宝衣[2;37;0m
战衣缘上刻着一行小字：神游(athoy)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "silk");
	set("wear_msg", "[1;37m$N穿上破云衣[2;37;0m\n");
	set("remove_msg", "[1;37m$N脱下坡云衣[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
