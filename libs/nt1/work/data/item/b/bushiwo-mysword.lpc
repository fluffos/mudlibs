// SN:]KNNOnm41\[D2bA[
// ITEM Made by player(慕容恪:bushiwo) /data/item/b/bushiwo-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Dec 14 02:34:38 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m血玲珑[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
这柄剑色作血红，仅剑刃处露出微微锋光。[2;37;0m
剑柄上刻着一行小字：慕容恪(bushiwo)
");
	set("value", 2100000);
	set("point", 250);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N冷哼一声，手按剑柄，扬手处$n[1;36m出鞘。\n[1;31m一声长吟，顿时血～光～漫～天～[2;37;0m\n");
	set("unwield_msg", "[1;32m$N吐一口气，信手将$n[1;32m收入鞘中，血光顿敛。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
