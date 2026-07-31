// SN:234X;eif9c]`j0H[
// ITEM Made by player(悟空:www) /data/item/w/www-wbb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr 22 04:51:53 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m五彩[1;35m宝莲衣[2;37;0m", ({ "wbb" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
摘取普陀山[1;37m五[1;33m彩[1;35m莲[1;32m叶[2;37;0m所制成的宝衣，拥有超强的防御力。[2;37;0m
战衣缘上刻着一行小字：悟空(www)
");
	set("value", 2100000);
	set("point", 848);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m五彩[1;35m宝莲衣[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m五彩[1;35m宝莲衣[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
