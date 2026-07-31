// SN:bMZZCNTKijdmeQne
// ITEM Made by player(武林列传:wllz) /data/item/w/wllz-awhip.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 10 01:10:08 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m雷神之链[2;37;0m", ({ "awhip" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一根鞭。
鞭柄上刻着一行小字：武林列传(wllz)
");
	set("value", 2100000);
	set("point", 883);
	set("material", "silk");
	set("wield_msg", "[1;31m$N猛然跃了起来，竟然将天空中闪烁的电光抓在手中。一瞬间，$N周身尽为电光笼罩。[2;37;0m\n");
	set("unwield_msg", "[1;33m$N周身闪烁的电光慢慢消去，渐渐收入手中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
