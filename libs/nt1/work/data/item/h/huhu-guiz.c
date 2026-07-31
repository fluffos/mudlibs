// SN:VP?lW\9m9;`dCTf1
// ITEM Made by player(胡归真:huhu) /data/item/h/huhu-guiz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 25 18:13:44 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m归真[2;37;0m", ({ "guiz" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m只听见「飕」地一声，胡归真的手中已经多了一把精铁加特殊材料虾制而成的宝剑——[1;37m归真[2;37;0m。[2;37;0m
剑柄上刻着一行小字：胡归真(huhu)
");
	set("value", 2100000);
	set("point", 264);
	set("material", "magic stone");
	set("wield_msg", "[1;37m$n[1;37m化作一道白光，冲天而起，以无比磅礴的气势矗立在你面前。[2;37;0m\n");
	set("unwield_msg", "[1;37m一道幽蓝的光线划过广漠的夜空，只是一瞬间，等你想仔细看清楚时，它已消失的无影无踪。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
