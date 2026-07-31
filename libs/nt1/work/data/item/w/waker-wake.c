// SN:ogEW<9LcRcYTQn8H
// ITEM Made by player(天贼:waker) /data/item/w/waker-wake.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jun 14 08:33:51 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m觉醒的命运[2;37;0m", ({ "wake" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;37m握住的武器是用来战斗的[1;31m握住了命运是用来改变人生的[2;37;0m
刀柄上刻着一行小字：天贼(waker)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;31m天空突然一声[1;36m惊雷[1;31m命运觉醒了[2;37;0m\n");
	set("unwield_msg", "[1;37m永远[1;36m闪耀的[1;31m命运[1;37m之[1;31m光[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
