// SN:YE]e5o=lUS;SB:;g
// ITEM Made by player(飞花:feihua) /data/item/f/feihua-feia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun May 30 18:13:57 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m追命[2;37;0m", ({ "feia" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
剑柄上刻着一行小字：飞花(feihua)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;31m我所思兮在云间，碧水秀兮心茫然，美人赠我玉青璇，侧身望兮泪沾翰。[2;37;0m\n");
	set("unwield_msg", "[1;31m我所思兮在南溟，闲来赏月又吟风，子陵仲少皆神龙，异日相逢大梦中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
