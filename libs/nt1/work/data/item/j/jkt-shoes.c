// SN:4]H89V5QE;Ufo`4o
// ITEM Made by player(渡独:jkt) /data/item/j/jkt-shoes.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May  9 04:55:26 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m绝尘[1;37m踏云[1;32m靴[2;37;0m", ({ "shoes" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
[1;37m这就是太上老君练的神靴，传说穿上能日行八千里。[2;37;0m
靴子缘上刻着一行小字：渡独(jkt)
");
	set("value", 2100000);
	set("point", 180);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;36m绝尘[1;37m踏云[1;32m靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m绝尘[1;37m踏云[1;32m靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
