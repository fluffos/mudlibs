// SN:C4E>joF`BnXMnnJW
// ITEM Made by player(逍遥一剑:klivers) /data/item/k/klivers-duanbing.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 17 19:55:27 2004
#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("精武短兵[2;37;0m", ({ "duanbing" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支短兵。
短兵柄上刻着一行小字：逍遥一剑(klivers)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_dagger(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
