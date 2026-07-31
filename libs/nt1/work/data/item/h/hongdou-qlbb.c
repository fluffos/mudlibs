// SN:g0[T@9fkjldU3SD9
// ITEM Made by player(红痕:hongdou) /data/item/h/hongdou-qlbb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 26 20:39:36 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m麒麟臂[2;37;0m", ({ "qlbb" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;33m没什么好看的，红痕的手臂而已。[2;37;0m
战衣缘上刻着一行小字：红痕(hongdou)
");
	set("value", 2100000);
	set("point", 408);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;31m麒麟臂[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;31m麒麟臂[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
