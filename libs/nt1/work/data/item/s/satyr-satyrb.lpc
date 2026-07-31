// SN:LD:D:mc>kYNm9gfo
// ITEM Made by player(蚂蚁:satyr) /data/item/s/satyr-satyrb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 13 08:27:56 2003
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m蚂蚁[1;31m腰[1;33m带[2;37;0m", ({ "satyrb" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
[1;31m看什么看[2;37;0m
腰带缘上刻着一行小字：蚂蚁(satyr)
");
	set("value", 2100000);
	set("point", 90);
	set("material", "silk");
	set("wear_msg", "[1;37m穿上[1;32m$N[1;31m腰[1;33m带[2;37;0m\n");
	set("remove_msg", "[1;37m脱下[1;32m$N[1;31m腰[1;33m带[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
