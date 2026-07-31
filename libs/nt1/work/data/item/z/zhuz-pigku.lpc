// SN:f@mU8:7@mn\i2ad5
// ITEM Made by player(真天蓬:zhuz) /data/item/z/zhuz-pigku.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug  7 09:19:13 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m内裤[2;37;0m", ({ "pigku" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：真天蓬(zhuz)
");
	set("value", 1500000);
	set("point", 156);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;31m内裤[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m内裤[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
