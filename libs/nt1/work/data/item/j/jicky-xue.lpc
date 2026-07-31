// SN:40T63Q[V;d7@?jf1
// ITEM Made by player(毛毛:jicky) /data/item/j/jicky-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 15 12:25:35 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m狂风靴[2;37;0m", ({ "xue" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：毛毛(jicky)
");
	set("value", 700000);
	set("point", 19);
	set("material", "iron");
	set("wear_msg", "[33m$N[33m装备[1;37m狂风靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m狂风靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
