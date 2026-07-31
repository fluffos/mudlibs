// SN:V@b0gePR;47WQHcJ
// ITEM Made by player(一灯:aaron) /data/item/a/aaron-goldjia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep  6 21:01:21 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("金甲[2;37;0m", ({ "goldjia" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：一灯(aaron)
");
	set("value", 2100000);
	set("point", 223);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备金甲[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了金甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
