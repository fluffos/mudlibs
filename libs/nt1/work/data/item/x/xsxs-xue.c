// SN:4Ig[7jfUE^@0dVbQ
// ITEM Made by player(欧阳血魔:xsxs) /data/item/x/xsxs-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 28 13:25:46 2004
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("雪血[2;37;0m", ({ "xue" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根杖。
杖柄上刻着一行小字：欧阳血魔(xsxs)
");
	set("value", 2100000);
	set("point", 144);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
