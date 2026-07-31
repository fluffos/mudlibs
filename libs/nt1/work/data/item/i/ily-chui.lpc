// SN:6UNTA=i`KP]clMQP
// ITEM Made by player(剑气横天:ily) /data/item/i/ily-chui.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 17 20:36:44 2004
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m雪域[1;31m苍狼[1;34m锤[2;37;0m", ({ "chui" }));
	set_weight(21000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把锤。
锤柄上刻着一行小字：剑气横天(ily)
");
	set("value", 2100000);
	set("point", 1304);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
