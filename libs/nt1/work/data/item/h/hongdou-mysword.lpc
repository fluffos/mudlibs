// SN:]]@VGJ=PnFK1<H6N
// ITEM Made by player(红豆:hongdou) /data/item/h/hongdou-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 29 00:34:06 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m道剑[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;36m这就是传说中的道家传宗[1;36m道剑[2;37;0m[2;37;0m
剑柄上刻着一行小字：红豆(hongdou)
");
	set("value", 2100000);
	set("point", 461);
	set("material", "magic stone");
	set("wield_msg", "[1;32m道剑传宗。[2;37;0m\n");
	set("unwield_msg", "[1;32m天尊同威。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
