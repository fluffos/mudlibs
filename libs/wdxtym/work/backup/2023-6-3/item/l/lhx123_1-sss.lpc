// ITEM Made by player(阿狸:lhx123_1) /data/item/l/lhx123_1-sss.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 23 22:26:38 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m水果刀[1;35m[2;37;0m", ({ "sss" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：阿狸(lhx123_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
