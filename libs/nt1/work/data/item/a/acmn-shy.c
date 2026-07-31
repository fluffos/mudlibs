// SN:;QOI3PGGWZn31\Pc
// ITEM Made by player(渡无:acmn) /data/item/a/acmn-shy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan 14 16:08:27 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m失魂引[2;37;0m", ({ "shy" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一根鞭。
[1;31m如蛟龙破空而出，灵蛇闪动不定[2;37;0m
鞭柄上刻着一行小字：渡无(acmn)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "silk");
	set("wield_msg", "[1;33m风起云涌，天空为之变色[2;37;0m\n");
	set("unwield_msg", "[1;37m失魂迷茫，如雪花飘飘洒洒而下，落地无声[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
