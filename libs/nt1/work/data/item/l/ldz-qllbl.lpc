// SN::5:n:HUARFiMOR7j
// ITEM Made by player(空浪:ldz) /data/item/l/ldz-qllbl.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Apr 20 19:48:01 2004
#include <ansi.h>
#include <weapon.h>

inherit DAGGER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m青龙[1;33m鳞二兵[2;37;0m", ({ "qllbl" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支短兵。
短兵柄上刻着一行小字：空浪(ldz)
");
	set("value", 2100000);
	set("point", 649);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一支[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_dagger(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
