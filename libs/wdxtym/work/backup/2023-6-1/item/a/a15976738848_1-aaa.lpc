// ITEM Made by player(等等:a15976738848_1) /data/item/a/a15976738848_1-aaa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 14 13:24:16 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("宿舍[2;37;0m", ({ "aaa" }));
	set_weight(1750);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：等等(a15976738848_1)
");
	set("value", 1500000);
	set("point", 154);
	set("material", "steel");
	set("wear_msg", "[33m$N[33m装备宿舍[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了宿舍[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
