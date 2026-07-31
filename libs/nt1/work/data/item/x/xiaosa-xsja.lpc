// SN:`I6cdmjP:GC=iZbm
// ITEM Made by player(小撒:xiaosa) /data/item/x/xiaosa-xsja.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 26 22:52:57 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("长剑[2;37;0m", ({ "xsja" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：小撒(xiaosa)
");
	set("value", 2100000);
	set("point", 318);
	set("material", "magic stone");
	set("wield_msg", "唰的一声拔出一把长剑。[2;37;0m\n");
	set("unwield_msg", "长剑一转，插在背后。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
