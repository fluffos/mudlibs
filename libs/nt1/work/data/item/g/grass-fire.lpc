// SN:]5^bjoGV8:0l=k`i
// ITEM Made by player(小草:grass) /data/item/g/grass-fire.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 18 01:49:32 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m流星[1;31m火雨[2;37;0m", ({ "fire" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
铁掌缘上刻着一行小字：小草(grass)
");
	set("value", 2100000);
	set("point", 682);
	set("material", "magic stone");
	set("wear_msg", "[1;37mなにぬねのはひ％……※×（——[1;37m流星[1;31m火雨[2;37;0m\n");
	set("remove_msg", "[1;37mなにぬねのはひ％……※×（——[1;37m流星[1;31m火雨[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);
	set("armor_prop/strike", 10);

	setup();
}

string long() { return query("long") + item_long(); }
