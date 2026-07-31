// SN:Hb72]jVoAQQbBPZT
// ITEM Made by player(慕容伤:levatin) /data/item/l/levatin-dunhuang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jul 23 23:29:54 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m邪剑敦煌[2;37;0m", ({ "dunhuang" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
上古十大邪器之一，为魔神蚩尤对抗黄帝时使用之魔剑，有翻江倒海之威力。[2;37;0m
剑柄上刻着一行小字：慕容伤(levatin)
");
	set("value", 2100000);
	set("point", 415);
	set("material", "magic stone");
	set("wield_msg", "[1;36m天空忽然传来了几声冷笑，霎时间乌云密布！一道[1;33m闪电[1;36m从天而降！[2;37;0m\n");
	set("unwield_msg", "[1;31m只见你的眼前一黑，接著什么也不知道了。。。。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
