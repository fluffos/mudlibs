// SN:n8H\WBaj6n`7N3:0
// ITEM Made by player(猎人:hunterx) /data/item/h/hunterx-uarepig.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 15 15:34:08 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m你是[1;31m猪[1;37m头[2;37;0m", ({ "uarepig" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[37m缠魂丝[2;37;0m炼制而成的一根鞭。
鞭柄上刻着一行小字：猎人(hunterx)
");
	set("value", 800000);
	set("point", 35);
	set("material", "silk");
	set("wield_msg", "[1;36m$N[1;36m一声清啸，抖出一根[1;36m$n[1;36m。[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
