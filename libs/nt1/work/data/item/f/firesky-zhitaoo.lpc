// SN:\SF;O1c2L801WGN`
// ITEM Made by player(飘摇一剑:firesky) /data/item/f/firesky-zhitaoo.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 21 18:16:38 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("指套套[2;37;0m", ({ "zhitaoo" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：飘摇一剑(firesky)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备指套套[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了指套套[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
