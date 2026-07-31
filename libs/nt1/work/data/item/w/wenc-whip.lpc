// SN:=[`_mJF0kU]dMIff
// ITEM Made by player(欧阳闻浩:wenc) /data/item/w/wenc-whip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Aug 26 02:57:47 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m缠魂索[2;37;0m", ({ "whip" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一根鞭。
鞭柄上刻着一行小字：欧阳闻浩(wenc)
");
	set("value", 2100000);
	set("point", 584);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
