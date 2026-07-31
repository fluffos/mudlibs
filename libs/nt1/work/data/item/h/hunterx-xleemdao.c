// SN:K60aXf0mLE?nAClS
// ITEM Made by player(猎人:hunterx) /data/item/h/hunterx-xleemdao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun  3 10:37:20 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m小李他妈的飞刀[2;37;0m", ({ "xleemdao" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;32m这就是小李他妈用的飞刀。很厉害的[2;37;0m
剑柄上刻着一行小字：猎人(hunterx)
");
	set("value", 2100000);
	set("point", 690);
	set("material", "magic stone");
	set("wield_msg", "[1;33mＨａｈａｈａｈａｈａ．．．．ｈａｈａ．．．．ｈａ．．ｈａｈ．．不好笑．．＝｜[2;37;0m\n");
	set("unwield_msg", "[1;33mＨａｈａｈａｈａｈａ．．．．ｈａｈａ．．．．ｈａ．．ｈａｈ．．我是天才．．＝）[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
