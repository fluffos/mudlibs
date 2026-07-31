// SN:]7BSkkh;Q=2L=DOg
// ITEM Made by player(麻仓叶:fire) /data/item/f/fire-grass.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr 27 14:53:35 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m情人草[2;37;0m", ({ "grass" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;35m这是一株蓬松轻盈，状如云雾的情人草，象征着爱意永恒。[2;37;0m
战衣缘上刻着一行小字：麻仓叶(fire)
");
	set("value", 2100000);
	set("point", 644);
	set("material", "silk");
	set("wear_msg", "[1;35m这是一株蓬松轻盈，状如云雾的情人草，象征着爱意永恒。[2;37;0m\n");
	set("remove_msg", "[1;35m这是一株蓬松轻盈，状如云雾的情人草，象征着爱意永恒。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
