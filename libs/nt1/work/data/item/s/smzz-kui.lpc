// SN:[bUmX;8CNJQY2]cd
// ITEM Made by player(张无忌:smzz) /data/item/s/smzz-kui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 26 01:33:29 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m光明[1;31m盔[2;37;0m", ({ "kui" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
[1;35m名教[1;31m教主[1;35m专用头盔[2;37;0m
头盔缘上刻着一行小字：张无忌(smzz)
");
	set("value", 2100000);
	set("point", 209);
	set("material", "magic stone");
	set("wear_msg", "[1;37m熊熊圣火[1;31m耀我中华[2;37;0m\n");
	set("remove_msg", "[1;37m熊熊圣火[1;31m燃我豪情[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
