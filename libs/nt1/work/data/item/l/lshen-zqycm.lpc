// SN:G]dWg8MaWKHbfA=R
// ITEM Made by player(洛神:lshen) /data/item/l/lshen-zqycm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 17 17:53:34 2004
#include <ansi.h>
#include <weapon.h>

inherit AXE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m朱雀[1;33m神斧[2;37;0m", ({ "zqycm" }));
	set_weight(13200);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把斧。
斧柄上刻着一行小字：洛神(lshen)
");
	set("value", 2100000);
	set("point", 1140);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_axe(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
