// ITEM Made by player(夜长歌:s7787888_1) /data/item/s/s7787888_1-zhengz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Mar 24 01:05:17 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("正宗[2;37;0m", ({ "zhengz" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;37m神魔[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：夜长歌(s7787888_1)
");
	set("value", 80100000);
	set("point", 8800);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
