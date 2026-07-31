// SN:TL0ZEo[V<@7iL]Za
// ITEM Made by player(净随:yaly) /data/item/y/yaly-pen.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 18 09:01:46 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m钢[1;37m笔[2;37;0m", ({ "pen" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
这是一只钢笔，看什么看，再看画你脸啦！小样！[2;37;0m
剑柄上刻着一行小字：净随(yaly)
");
	set("value", 2100000);
	set("point", 290);
	set("material", "magic stone");
	set("wield_msg", "[1;37m一把小钢笔，[1;36m没什么好描述的！[1;31m不写啦！！！[2;37;0m\n");
	set("unwield_msg", "[1;37m收工啦！[1;36m回家！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
