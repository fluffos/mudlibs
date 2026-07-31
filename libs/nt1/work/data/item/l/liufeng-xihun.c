// SN:PaYC6Ea`9W]5og?]
// ITEM Made by player(流风:liufeng) /data/item/l/liufeng-xihun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Nov 22 16:50:40 2003
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m吸魂[2;37;0m", ({ "xihun" }));
	set_weight(21000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把锤。
锤柄上刻着一行小字：流风(liufeng)
");
	set("value", 2100000);
	set("point", 205);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
