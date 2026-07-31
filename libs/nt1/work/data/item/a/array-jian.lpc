// SN:7Cbc==TDAVY;GAi>
// ITEM Made by player(艾汀:array) /data/item/a/array-jian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Nov 25 15:59:19 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m武林列传追杀令[2;37;0m", ({ "jian" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一柄剑。
[1;31m武林列传追杀令一出，[30m你们[1;31m最好不要自寻死路[2;37;0m
剑柄上刻着一行小字：艾汀(array)
");
	set("value", 4100000);
	set("point", 2812);
	set("material", "tian jing");
	set("wield_msg", "[1;37m武林列传追杀令[2;37;0m\n");
	set("unwield_msg", "[1;36m武林列传追杀令[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
