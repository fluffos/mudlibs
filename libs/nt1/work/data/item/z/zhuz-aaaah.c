// SN:A@4EZRl_ZlO:gGF[
// ITEM Made by player(真天蓬:zhuz) /data/item/z/zhuz-aaaah.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug 21 08:05:02 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("大大[2;37;0m", ({ "aaaah" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[37m缠魂丝[2;37;0m炼制而成的一条腰带。
腰带缘上刻着一行小字：真天蓬(zhuz)
");
	set("value", 800000);
	set("point", 31);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备大大[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了大大[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
