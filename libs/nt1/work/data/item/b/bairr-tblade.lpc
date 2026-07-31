// SN:B@CFRSclJHcY6Y[g
// ITEM Made by player(白蕊儿:bairr) /data/item/b/bairr-tblade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 16 20:14:16 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("测试刀[2;37;0m", ({ "tblade" }));
	set_weight(6750);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[37m精铁[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：白蕊儿(bairr)
");
	set("value", 700000);
	set("point", 30);
	set("material", "iron");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
