// SN:f88_TKDmUG:31J_L
// ITEM Made by player(龙八:sbf) /data/item/s/sbf-sigh.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Aug  1 20:26:08 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m铅[1;37m笔[2;37;0m", ({ "sigh" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m这真的只是一把[1;31m剑，[1;34m没什么好看的！[1;33m别看了！！！[2;37;0m
剑柄上刻着一行小字：龙八(sbf)
");
	set("value", 2100000);
	set("point", 211);
	set("material", "magic stone");
	set("wield_msg", "[1;37m天空不[1;31m动，[1;34m地面也不[1;31m动，[1;33m真的什么事都没[1;34m发生！[1;37m没劲！！！[2;37;0m\n");
	set("unwield_msg", "[1;37m天[1;34m黑[1;31m啦！[1;36m回家洗洗睡吧！！！[1;33m无聊！！！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
