// SN:l2Z0lCIS7VU:fU?Z
// ITEM Made by player(拾荒者:walker) /data/item/w/walker-walkerd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 11 03:37:14 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m野蛮人[37m腰带[2;37;0m", ({ "walkerd" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：拾荒者(walker)
");
	set("value", 2100000);
	set("point", 180);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[33m野蛮人[37m腰带[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[33m野蛮人[37m腰带[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
