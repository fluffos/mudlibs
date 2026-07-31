// SN:dW0mkXObE9GCTW=L
// ITEM Made by player(胡老头:qsnx) /data/item/q/qsnx-buyi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 17 22:46:09 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("布衣[2;37;0m", ({ "buyi" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：胡老头(qsnx)
");
	set("value", 2100000);
	set("point", 378);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备布衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了布衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
