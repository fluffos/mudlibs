// SN:o23aS_g\<P9Xg_SL
// ITEM Made by player(狗狗狗:google) /data/item/g/google-ggtooth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 19 13:28:28 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m咬遍天下无敌牙[2;37;0m", ({ "ggtooth" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一柄剑。
[1;36m咬咬咬！！！！！！！一个字，就是——咬！[2;37;0m
剑柄上刻着一行小字：狗狗狗(google)
");
	set("value", 4100000);
	set("point", 1840);
	set("material", "tian jing");
	set("wield_msg", "[1;31m嗷嗷嗷嗷～～～～～[2;37;0m\n");
	set("unwield_msg", "[1;36m狗狗咬了一口，跑开叻！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
