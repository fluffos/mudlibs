// SN:3oci=2C;>V[RlS1O
// ITEM Made by player(勇哥:hanweiyong) /data/item/h/hanweiyong-han.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Apr 24 22:24:28 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m裁决[2;37;0m", ({ "han" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;35m这是一把专门用来杀死诅玛教主的裁决之杖[2;37;0m
剑柄上刻着一行小字：勇哥(hanweiyong)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;31m让就一个字，我只说一次，不要让我用行动表示，否则让你看黑白电视[2;37;0m\n");
	set("unwield_msg", "[1;37m在这月黑风高的八月十五的夜晚，俺大声呼道：瞧你这小样，和那猴子猩猩没有两样，想约我啊，下辈子再讲[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
