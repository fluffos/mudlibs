// SN:\lJZ721<]:>lH0ec
// ITEM Made by player(纲手:tsunade) /data/item/t/tsunade-shen.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 24 11:47:44 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m刹神[2;37;0m", ({ "shen" }));
	set_weight(2025);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[2;37;0m[1;31m雷火寒晶[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：纲手(tsunade)
");
	set("value", 1);
	set("point", 360300);
	set("material", "stone");
	set("wear_msg", "[33m$N[33m装备[1;31m刹神[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m刹神[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
