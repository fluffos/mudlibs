// SN:QIAYY[DXK9SXm9DT
// ITEM Made by player(浪荡子:ldz) /data/item/l/ldz-qllac.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 15 23:48:32 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m青龙[1;33m鳞一靴[2;37;0m", ({ "qllac" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
靴子缘上刻着一行小字：浪荡子(ldz)
");
	set("value", 2100000);
	set("point", 257);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;36m青龙[1;33m鳞一靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m青龙[1;33m鳞一靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
