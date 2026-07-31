// ITEM Made by player(慕容茉儿:jingxin_1) /data/item/j/jingxin_1-lil.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 23 00:05:59 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m无名[2;37;0m", ({ "lil" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：慕容茉儿(jingxin_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
