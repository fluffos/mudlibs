// SN:T@7HKo35426WgNcT
// ITEM Made by player(鬼舞火:gwhuo) /data/item/g/gwhuo-longgun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Dec  8 08:48:06 2003
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m青龙杖[2;37;0m", ({ "longgun" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根杖。
这是猪猪给小龙的龙杖[2;37;0m
杖柄上刻着一行小字：鬼舞火(gwhuo)
");
	set("value", 2100000);
	set("point", 392);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
