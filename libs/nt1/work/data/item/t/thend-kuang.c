// SN:QQ8@dX:^TEn1CJ71
// ITEM Made by player(备溪:thend) /data/item/t/thend-kuang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Nov 25 12:18:21 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m狂风快剑[2;37;0m", ({ "kuang" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m质地轻柔，剑光慑人[2;37;0m
剑柄上刻着一行小字：备溪(thend)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wield_msg", "一声龙吟，[1;37m狂风快剑[2;37;0m已在手中[2;37;0m\n");
	set("unwield_msg", "[1;37m狂风快剑[2;37;0m落入剑鞘[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
