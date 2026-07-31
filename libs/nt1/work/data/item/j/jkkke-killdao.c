// SN:8__enId1eSnPEcaN
// ITEM Made by player(血魔狂龙:jkkke) /data/item/j/jkkke-killdao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 17 22:14:54 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("要命[2;37;0m", ({ "killdao" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一把刀。
杀人无形[2;37;0m
刀柄上刻着一行小字：血魔狂龙(jkkke)
");
	set("value", 1500000);
	set("point", 70);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
