// SN:MY^A@@6mk2eB>Q6:
// ITEM Made by player(王从阳:hatebj) /data/item/h/hatebj-kaijia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Feb  9 21:14:28 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m明光铠[2;37;0m", ({ "kaijia" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
护甲缘上刻着一行小字：王从阳(hatebj)
");
	set("value", 2100000);
	set("point", 205);
	set("material", "silk");
	set("wear_msg", "[33m$N穿上一套$n[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N把$n[33m脱了下来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
