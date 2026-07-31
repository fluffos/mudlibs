// SN:]TlR0P@SkMBQd8l5
// ITEM Made by player(宇文成都:hughes) /data/item/h/hughes-caidai.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Oct  1 20:54:05 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m五彩华带[2;37;0m", ({ "caidai" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
[1;31m火红的五彩华带[2;37;0m
腰带缘上刻着一行小字：宇文成都(hughes)
");
	set("value", 2100000);
	set("point", 71);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;31m五彩华带[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m五彩华带[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
