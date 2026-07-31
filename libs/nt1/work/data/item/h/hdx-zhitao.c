// SN:B43R4g:\eHILn@0N
// ITEM Made by player(段老二:hdx) /data/item/h/hdx-zhitao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr 17 18:35:36 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m小老二[2;37;0m", ({ "zhitao" }));
	set_weight(1750);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：段老二(hdx)
");
	set("value", 1500000);
	set("point", 160);
	set("material", "steel");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[33m小老二[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[33m小老二[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
