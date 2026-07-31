// SN:lRDoZDAQN?Y]35oW
// ITEM Made by player(水灵:fireice) /data/item/f/fireice-water.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Nov 24 09:53:00 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m水神[2;37;0m", ({ "water" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
[1;33m它是传说中水神的化身[2;37;0m
靴子缘上刻着一行小字：水灵(fireice)
");
	set("value", 2100000);
	set("point", 86);
	set("material", "magic stone");
	set("wear_msg", "[1;33m踏水而走[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m水神[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
