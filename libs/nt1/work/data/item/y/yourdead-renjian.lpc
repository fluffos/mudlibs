// SN:YS:LFli3m\`AXj6R
// ITEM Made by player(渡会:yourdead) /data/item/y/yourdead-renjian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun 25 19:10:07 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("仁者之心[2;37;0m", ({ "renjian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：渡会(yourdead)
");
	set("value", 2100000);
	set("point", 176);
	set("material", "magic stone");
	set("wield_msg", "仁者之心一声长呜，自动离鞘而出\n侠义之气由然而生[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
