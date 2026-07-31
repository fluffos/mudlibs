// SN:bkn_]6iUDUYFRWaj
// ITEM Made by player(酷头裤头:kutou) /data/item/k/kutou-dxw.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Dec 13 15:46:08 2003
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m大邪王[2;37;0m", ({ "dxw" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;31m邪王百劫屠尽众神[2;37;0m
刀柄上刻着一行小字：酷头裤头(kutou)
");
	set("value", 2100000);
	set("point", 221);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
