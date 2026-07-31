// SN:a_EVgjRND6;OmFK>
// ITEM Made by player(断武:godrod) /data/item/g/godrod-circle.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 22 08:39:17 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m两[1;36m仪[1;37m护手[2;37;0m", ({ "circle" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
两仪乃由太极而生，正反相合，生生不息。[2;37;0m
铁掌缘上刻着一行小字：断武(godrod)
");
	set("value", 2100000);
	set("point", 244);
	set("material", "magic stone");
	set("wear_msg", "[1;37m$N[1;37m将$n[1;37m穿戴上，但见双掌舞动之中，泛著一股[1;33m生生不息[1;37m的气势！[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m两[1;36m仪[1;37m护手[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
