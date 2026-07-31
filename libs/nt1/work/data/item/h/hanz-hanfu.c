// SN:`_o7`SQZ4DYcGa6F
// ITEM Made by player(韩子奇:hanz) /data/item/h/hanz-hanfu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Sep 19 12:41:59 2004
#include <ansi.h>
#include <weapon.h>

inherit AXE;
inherit F_ITEMMAKE;

void create()
{
	set_name("雷霆斧[2;37;0m", ({ "hanfu" }));
	set_weight(13200);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把斧。
斧柄上刻着一行小字：韩子奇(hanz)
");
	set("value", 2100000);
	set("point", 345);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_axe(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
