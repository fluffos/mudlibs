// SN:O?K6QcT7[`mn33RH
// ITEM Made by player(少龙:lhp) /data/item/l/lhp-xue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun  9 17:52:50 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m天下有雪[2;37;0m", ({ "xue" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;37m天地苍茫，风雪人间[2;37;0m
剑柄上刻着一行小字：少龙(lhp)
");
	set("value", 2100000);
	set("point", 682);
	set("material", "magic stone");
	set("wield_msg", "[1;37m我又回头去追去醉，就算我追到最後只剩冰雪，天都为我伤悲冷的爱快枯萎，任漫天风雪覆盖我的心碎[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
