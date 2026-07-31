// SN:Y<3FKj0];i345>_M
// ITEM Made by player(黄蓉:ronger) /data/item/r/ronger-yuxiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 13 09:43:51 2004
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m知音少[2;37;0m", ({ "yuxiao" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支箫。
箫柄上刻着一行小字：黄蓉(ronger)
");
	set("value", 2100000);
	set("point", 237);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
