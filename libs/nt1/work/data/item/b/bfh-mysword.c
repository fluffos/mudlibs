// SN:UPNf3XnX@aTU=276
// ITEM Made by player(跋锋寒:bfh) /data/item/b/bfh-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug 21 12:40:38 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m刺[34m天[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：跋锋寒(bfh)
");
	set("value", 2100000);
	set("point", 470);
	set("material", "magic stone");
	set("wield_msg", "[1;31m$N心随意动，内息霎时爆发，刺天发出铮铮合音，杀意四处流溢[2;37;0m\n");
	set("unwield_msg", "[1;36m$N收回内劲，刺天缓缓恢复平静，消失在无尽空间[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
