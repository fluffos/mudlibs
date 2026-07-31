// SN:Il6oNGbYDeooT85W
// ITEM Made by player(红莲老祖:redl) /data/item/r/redl-lha.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jan 23 06:32:18 2004
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m莲花杖[2;37;0m", ({ "lha" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根杖。
杖柄上刻着一行小字：红莲老祖(redl)
");
	set("value", 2100000);
	set("point", 283);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
