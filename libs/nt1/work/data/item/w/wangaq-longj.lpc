// SN:k5LcRES3[`QIeU0;
// ITEM Made by player(烟火飞散:wangaq) /data/item/w/wangaq-longj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Nov 13 05:58:16 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m水[1;32m龙[1;31m剑[2;37;0m", ({ "longj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
长啸一声一道白光直冲霄汉[2;37;0m
剑柄上刻着一行小字：烟火飞散(wangaq)
");
	set("value", 2100000);
	set("point", 123);
	set("material", "magic stone");
	set("wield_msg", "长啸一声一道白光直冲霄汉[2;37;0m\n");
	set("unwield_msg", "长啸一声一道白光直冲霄汉[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
