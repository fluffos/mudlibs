// SN:0Nih^GPhER>g1Y1G
// ITEM Made by player(闲人:xren) /data/item/x/xren-xieyou.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jan 10 17:36:27 2004
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m鞋油[2;37;0m", ({ "xieyou" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一根杖。
杖柄上刻着一行小字：闲人(xren)
");
	set("value", 700000);
	set("point", 44);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
