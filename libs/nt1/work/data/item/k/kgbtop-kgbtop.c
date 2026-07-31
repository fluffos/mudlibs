// SN:;0E6<<9^6Q6M9bao
// ITEM Made by player(渡觉:kgbtop) /data/item/k/kgbtop-kgbtop.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Jun 26 22:49:58 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("古灵[2;37;0m", ({ "kgbtop" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
此剑冷气森森，寒气袭人，看后不觉打了寒战[2;37;0m
剑柄上刻着一行小字：渡觉(kgbtop)
");
	set("value", 2100000);
	set("point", 189);
	set("material", "magic stone");
	set("wield_msg", "之间天山忽然有人喊了一声：“打雷啦，要下雨了，大家收被子啊”[2;37;0m\n");
	set("unwield_msg", "$N随手一抹，收起了$n。\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
