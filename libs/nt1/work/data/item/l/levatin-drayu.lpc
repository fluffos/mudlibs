// SN:251Pd4LYMIY=f_3T
// ITEM Made by player(慕容伤:levatin) /data/item/l/levatin-drayu.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jun 21 01:54:18 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m魔阴血玉[2;37;0m", ({ "drayu" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
血魔之血幻化而成，佩带者将拥有无比巨大的力量。[2;37;0m
腰带缘上刻着一行小字：慕容伤(levatin)
");
	set("value", 2100000);
	set("point", 129);
	set("material", "silk");
	set("wear_msg", "[1;36m突然间$N张开他的嘴，露出两颗异常尖锐的[1;37m獠牙[1;36m，以闪电般的速度向你扑了过去，你只觉脖子一凉，[1;31m血液[1;36m象泉水般涌进$N的嘴里，接着你昏了过去。[2;37;0m\n");
	set("remove_msg", "[1;33m不知道过了多久，你醒了过来，发现脖子居然没有受伤，隐约感到什么地方不对，但又说不出来，只觉得身体里面充满了力量。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
