// SN::K7^SO:NP^lRT=FG
// ITEM Made by player(红痕:hongdou) /data/item/h/hongdou-renb.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Oct 26 20:33:46 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m磐龙疾风刃[2;37;0m", ({ "renb" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;36m一把巨大的剑，看样子十分沉重。估计用这把剑的人力气很大。[2;37;0m
剑柄上刻着一行小字：红痕(hongdou)
");
	set("value", 2100000);
	set("point", 408);
	set("material", "magic stone");
	set("wield_msg", "[1;37m只听金属撞击声越来越重$N定睛一看[1;32m磐龙疾风刃\n[1;35m竟然自$N背后冉冉升起。\n[1;36m$N越到空中一把抓住[1;32m磐龙疾风刃[2;37;0m\n");
	set("unwield_msg", "[1;31m$N拍了拍[1;32m磐龙疾风刃[1;31m竟似对待多年的老友一般，杀意一消，[1;32m磐龙疾风刃[1;31m缓缓回鞘。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
