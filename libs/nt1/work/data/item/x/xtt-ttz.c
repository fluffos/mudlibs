// SN:`3TQk2TAHh31HIKX
// ITEM Made by player(小谭谭:xtt) /data/item/x/xtt-ttz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  2 01:07:01 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("谭谭掌[2;37;0m", ({ "ttz" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：小谭谭(xtt)
");
	set("value", 2100000);
	set("point", 214);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备谭谭掌[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了谭谭掌[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
