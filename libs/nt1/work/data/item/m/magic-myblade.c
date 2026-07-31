// SN:L<]GEeX3Be2:DGL1
// ITEM Made by player(慕容霜天:magic) /data/item/m/magic-myblade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jan 29 17:20:38 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m残情神刀[2;37;0m", ({ "myblade" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：慕容霜天(magic)
");
	set("value", 2100000);
	set("point", 269);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
