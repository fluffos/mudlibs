// SN:28j;[Mg1=R>;8QZD
// ITEM Made by player(拾荒者:walker) /data/item/w/walker-walkeri.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Sep 11 03:47:26 2004
#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m暗黑[33m破烂刃[2;37;0m", ({ "walkeri" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支短兵。
短兵柄上刻着一行小字：拾荒者(walker)
");
	set("value", 2100000);
	set("point", 452);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_dagger(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
