// SN:JK;LoME5G1o19H3@
// ITEM Made by player(布衣:cloth) /data/item/c/cloth-yywd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Nov  1 13:12:05 2003
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m圆月弯刀[2;37;0m", ({ "yywd" }));
	set_weight(5100);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;36m离[1;31m火[1;36m玄[1;37m冰[1;36m玉[2;37;0m炼制而成的一把刀。
[1;33m可以随便喀查人的神刀[2;37;0m
刀柄上刻着一行小字：布衣(cloth)
");
	set("value", 1900000);
	set("point", 198);
	set("material", "stone");
	set("wield_msg", "[1;33m弯刀一现，神鬼莫现[2;37;0m\n");
	set("unwield_msg", "[1;33m弯刀不现，神鬼都现[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
