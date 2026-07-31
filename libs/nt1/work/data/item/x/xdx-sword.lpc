// SN:JN^0?@cjIe2U\19b
// ITEM Made by player(净玄:xdx) /data/item/x/xdx-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Aug 27 05:17:54 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m天堂[1;31m之令[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
我不入天堂谁入天堂[2;37;0m
剑柄上刻着一行小字：净玄(xdx)
");
	set("value", 2100000);
	set("point", 191);
	set("material", "magic stone");
	set("wield_msg", "[1;31m舌尖一咬。猛抽一条[1;37m红塔山，[1;31m喷出一口烟，运起葵花神功已将全身潜力尽数提起！[2;37;0m\n");
	set("unwield_msg", "[1;31m舌尖一咬。猛抽一条红塔山，喷出一口烟，运起发呆神功已将全身潜力尽数提起！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
