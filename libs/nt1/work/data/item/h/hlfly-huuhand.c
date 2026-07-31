// SN:ZILjd=E^Sf7C9`Eh
// ITEM Made by player(胡乱飞:hlfly) /data/item/h/hlfly-huuhand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct 17 21:58:58 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("胡乱掌[2;37;0m", ({ "huuhand" }));
	set_weight(2250);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：胡乱飞(hlfly)
");
	set("value", 1500000);
	set("point", 102);
	set("material", "steel");
	set("wear_msg", "[33m$N[33m装备胡乱掌[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了胡乱掌[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
