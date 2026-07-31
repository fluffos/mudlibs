// SN:j7^>YJo[nk44Y]T?
// ITEM Made by player(渡邪:xuan) /data/item/x/xuan-dcxj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep 11 19:20:29 2003
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m东成西就[2;37;0m", ({ "dcxj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;31m一把锋利的[1;37m东成西就[2;37;0m，
[1;31m它在阳光下闪闪发光。[2;37;0m
刀柄上刻着一行小字：渡邪(xuan)
");
	set("value", 2100000);
	set("point", 282);
	set("material", "magic stone");
	set("wield_msg", "[1;31m霹雳雷电精剪刀！\n自摸满贯对对碰！[2;37;0m\n");
	set("unwield_msg", "[1;31m我加速，丢丢丢，丢丢丢。\n丢丢丢丢丢丢丢。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
