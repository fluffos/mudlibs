// SN:<h1:\IFR0B<:28F7
// ITEM Made by player(不如跳舞:windance) /data/item/w/windance-yao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 25 19:08:57 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m命运[2;37;0m", ({ "yao" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：不如跳舞(windance)
");
	set("value", 2100000);
	set("point", 112);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[2;37;0m[34m命运[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[2;37;0m[34m命运[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
