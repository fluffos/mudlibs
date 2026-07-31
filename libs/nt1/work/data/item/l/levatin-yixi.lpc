// SN:\4QZ87BF\Sj2@L4>
// ITEM Made by player(慕容伤:levatin) /data/item/l/levatin-yixi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 16 20:50:45 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m魔剑一夕[2;37;0m", ({ "yixi" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
历代邪皇的佩剑，传说有翻天覆地的威力。[2;37;0m
剑柄上刻着一行小字：慕容伤(levatin)
");
	set("value", 2100000);
	set("point", 322);
	set("material", "magic stone");
	set("wield_msg", "[34m一道蓝光闪电般的向你劈了过来，你一时还没反应过来，它已经穿透了你的身体，你立时觉得浑身冰冷，犹如掉进了冰窖一般。[2;37;0m\n");
	set("unwield_msg", "[34m一切都过去了，你突然发现你的胸口多了个碗大的血洞。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
