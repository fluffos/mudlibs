// SN:V>oNQh39:895L?fL
// ITEM Made by player(欧阳静:xue) /data/item/x/xue-zhang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 20 23:12:23 2004
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m血[1;32m绿[1;33m杖[2;37;0m", ({ "zhang" }));
	set_weight(7500);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[37m上古寒铁[2;37;0m炼制而成的一根杖。
杖柄上刻着一行小字：欧阳静(xue)
");
	set("value", 1500000);
	set("point", 112);
	set("material", "steel");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
