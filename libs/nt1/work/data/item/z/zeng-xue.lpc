// SN:6@2V0>n\3?Bcf2Wi
// ITEM Made by player(水水:zeng) /data/item/z/zeng-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 17 08:50:06 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m火麒麟之靴[2;37;0m", ({ "xue" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;31m强大的魔导师水水所穿的套装之一[2;37;0m
靴子缘上刻着一行小字：水水(zeng)
");
	set("value", 2100000);
	set("point", 89);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;31m火麒麟之靴[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m火麒麟之靴[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
