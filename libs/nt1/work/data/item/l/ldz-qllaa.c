// SN:VB?980G`JK>ieXEF
// ITEM Made by player(浪荡子:ldz) /data/item/l/ldz-qllaa.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 15 23:46:52 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m青龙[1;33m鳞一甲[2;37;0m", ({ "qllaa" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：浪荡子(ldz)
");
	set("value", 2100000);
	set("point", 514);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;36m青龙[1;33m鳞一甲[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m青龙[1;33m鳞一甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
