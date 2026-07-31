// SN:TBbMCFMg9MVeZ58d
// ITEM Made by player(剑气横天:ily) /data/item/i/ily-bian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jul 17 20:34:17 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m雪域[1;31m苍狼[1;34m鞭[2;37;0m", ({ "bian" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一根鞭。
鞭柄上刻着一行小字：剑气横天(ily)
");
	set("value", 2100000);
	set("point", 1304);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
