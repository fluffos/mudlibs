// SN:N`nhiCe3:\WPIUBZ
// ITEM Made by player(慕容疯:kimura) /data/item/k/kimura-suiya.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov  9 17:48:09 2003
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m铁碎牙[2;37;0m", ({ "suiya" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m他有牙齿唷会咬人唷[2;37;0m
剑柄上刻着一行小字：慕容疯(kimura)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;37m一仰脖，吞下了一颗[1;35m玄黄紫清丹[1;37m，只见你浑身一颤，七窍都冒出白烟来。[2;37;0m\n");
	set("unwield_msg", "[1;31m刹那间只见飞花全身顿时浮现出一层刚猛的劲气，将你全全笼罩。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
