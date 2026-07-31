// SN:^40LnDYJ6S:LfRVI
// ITEM Made by player(虚伊:gmyr) /data/item/g/gmyr-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 27 07:39:39 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m地狱[1;32m追魂[1;37m令[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
地狱的镇殿神物[2;37;0m
剑柄上刻着一行小字：虚伊(gmyr)
");
	set("value", 2100000);
	set("point", 190);
	set("material", "magic stone");
	set("wield_msg", "[1;31m默运九阳神功，将内力积聚于鼻孔，一散全身浑然有力，坚不可摧。[2;37;0m\n");
	set("unwield_msg", "默运九阳神功，将内力积聚于鼻孔，一散全身浑然有力，坚不可摧。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
