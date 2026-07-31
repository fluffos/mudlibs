// SN:0i[39N1n884>Cbj7
// ITEM Made by player(一灯:aaron) /data/item/a/aaron-golddao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep  7 11:20:08 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("杀人刀[2;37;0m", ({ "golddao" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
刀柄上刻着一行小字：一灯(aaron)
");
	set("value", 2100000);
	set("point", 223);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一把[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
