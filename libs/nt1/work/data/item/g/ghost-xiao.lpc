// SN:J``>R1cU]X\B3DB4
// ITEM Made by player(静香:ghost) /data/item/g/ghost-xiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May  8 04:26:55 2004
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[30m碧海潮生按玉箫[2;37;0m", ({ "xiao" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支箫。
箫柄上刻着一行小字：静香(ghost)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
