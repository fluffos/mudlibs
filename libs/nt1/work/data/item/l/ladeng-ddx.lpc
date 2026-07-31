// SN:5OZ]Y3E7ZBL?N71<
// ITEM Made by player(本拉灯:ladeng) /data/item/l/ladeng-ddx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Jun 29 09:45:04 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m登[1;33m登[1;33m靴[2;37;0m", ({ "ddx" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：本拉灯(ladeng)
");
	set("value", 2100000);
	set("point", 58);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;33m登[1;33m登[1;33m靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;33m登[1;33m登[1;33m靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
