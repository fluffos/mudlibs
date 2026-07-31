// SN:@lY4QPo?3TFH?@UC
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-strikea.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug 28 00:21:44 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m白莲[1;32m叶掌[2;37;0m", ({ "strikea" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 1307);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m白莲[1;32m叶掌[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m白莲[1;32m叶掌[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
