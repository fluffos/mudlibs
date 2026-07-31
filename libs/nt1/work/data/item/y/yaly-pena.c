// SN:QcZ7[@ek=7:<lM0@
// ITEM Made by player(净随:yaly) /data/item/y/yaly-pena.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 14 10:22:07 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m指环[2;37;0m", ({ "pena" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
唉，不是什么值钱的东东！！不用看了！！[2;37;0m
指套缘上刻着一行小字：净随(yaly)
");
	set("value", 2100000);
	set("point", 396);
	set("material", "magic stone");
	set("wear_msg", "[1;37m戴上它，好像强了点！！！[2;37;0m\n");
	set("remove_msg", "[1;36m烦，[1;31m脱！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
