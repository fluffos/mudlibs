// SN:0RZkmbH0XclmM^8C
// ITEM Made by player(慕容一:gege) /data/item/g/gege-gxue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov 14 23:29:55 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m黑龙靴[2;37;0m", ({ "gxue" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;32m纹着黑龙的古战靴[2;37;0m
靴子缘上刻着一行小字：慕容一(gege)
");
	set("value", 2100000);
	set("point", 40);
	set("material", "silk");
	set("wear_msg", "[1;31m一道黑龙光，直冲霄汉[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;32m黑龙靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
