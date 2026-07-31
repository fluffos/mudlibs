// SN:GO^AAcM6H=eURPU]
// ITEM Made by player(逗你玩:asd) /data/item/a/asd-asdc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug  3 22:23:03 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("冰蚕带[2;37;0m", ({ "asdc" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：逗你玩(asd)
");
	set("value", 2100000);
	set("point", 177);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备冰蚕带[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了冰蚕带[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
