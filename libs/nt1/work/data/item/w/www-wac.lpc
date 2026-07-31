// SN:XdeZ39P7VgNSMJZ2
// ITEM Made by player(悟空:www) /data/item/w/www-wac.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jan 29 01:10:41 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m藕丝[1;34m步云履[2;37;0m", ({ "wac" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
龙宫的宝物，穿上它常人亦可行走如飞、腾云驾雾。
北海龙王敖顺所赠。[2;37;0m
靴子缘上刻着一行小字：悟空(www)
");
	set("value", 2100000);
	set("point", 154);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m藕丝[1;34m步云履[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m藕丝[1;34m步云履[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
