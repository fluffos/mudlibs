// SN:A3j[^kSgE`_Mc@kX
// ITEM Made by player(胡乱飞:hlfly) /data/item/h/hlfly-huudai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr  1 09:23:36 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("胡乱腰带[2;37;0m", ({ "huudai" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：胡乱飞(hlfly)
");
	set("value", 2100000);
	set("point", 107);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备胡乱腰带[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了胡乱腰带[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
