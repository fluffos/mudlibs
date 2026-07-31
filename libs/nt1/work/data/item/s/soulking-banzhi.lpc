// SN:H=eD50Y5\j?0c7d0
// ITEM Made by player(杨云:soulking) /data/item/s/soulking-banzhi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 13 21:54:11 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("碎心的扳指[2;37;0m", ({ "banzhi" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
平凡的物件必有不平凡之处[2;37;0m
指套缘上刻着一行小字：杨云(soulking)
");
	set("value", 2100000);
	set("point", 139);
	set("material", "magic stone");
	set("wear_msg", "暗淡的悠光闪过你以装备完成[2;37;0m\n");
	set("remove_msg", "火焰般的白光闪过你以取下装备[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
