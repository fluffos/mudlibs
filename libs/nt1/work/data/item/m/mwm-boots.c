// SN:l4TkUZOQ0kY@2`aD
// ITEM Made by player(段手:mwm) /data/item/m/mwm-boots.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct 13 01:06:33 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("皮鞋[2;37;0m", ({ "boots" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：段手(mwm)
");
	set("value", 2100000);
	set("point", 82);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备皮鞋[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了皮鞋[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
