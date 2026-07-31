// SN:cQB0i[TkaD]iD6Vk
// ITEM Made by player(易沐风:yfeng) /data/item/y/yfeng-finger.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug  1 06:41:04 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m归灵[1;32m指套[2;37;0m", ({ "finger" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;37m垃圾[2;37;0m
指套缘上刻着一行小字：易沐风(yfeng)
");
	set("value", 2100000);
	set("point", 173);
	set("material", "magic stone");
	set("wear_msg", "[1;31m看起来[33m$N[1;31m想杀死你！[2;37;0m\n");
	set("remove_msg", "[1;37m啊，你死了！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/claw", 10);
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
