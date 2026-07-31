// SN:4181Jo<ReB62A\DH
// ITEM Made by player(唐活活:down) /data/item/d/down-sword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jul 21 11:55:47 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("我的剑[2;37;0m", ({ "sword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
这是一把不错的剑[2;37;0m
剑柄上刻着一行小字：唐活活(down)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "一把拔出了我的剑[2;37;0m\n");
	set("unwield_msg", "我的剑突然没了棕影[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
