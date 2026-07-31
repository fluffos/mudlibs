// SN:[4BE^O0Vc]Id7M2n
// ITEM Made by player(肯德鸡:kfc) /data/item/k/kfc-akfc.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 30 21:40:46 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m肯德基[1;32m雪糕筒[2;37;0m", ({ "akfc" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：肯德鸡(kfc)
");
	set("value", 2100000);
	set("point", 416);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一柄[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
