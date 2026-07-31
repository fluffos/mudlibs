// SN:fOOJddW54@TK:im6
// ITEM Made by player(艾汀:array) /data/item/a/array-mysword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 17 21:01:00 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m湘妃竹[2;37;0m", ({ "mysword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：艾汀(array)
");
	set("value", 2100000);
	set("point", 1151);
	set("material", "magic stone");
	set("wield_msg", "[1;33m$N呆了一呆，慢慢随风而舞，居然就变成了一株$n[1;33m。[2;37;0m\n");
	set("unwield_msg", "[1;36m竹叶轻盈，就仿佛那已久远的思念。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
