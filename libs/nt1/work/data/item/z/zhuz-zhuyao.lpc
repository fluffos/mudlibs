// SN:5>?ACSjoX:VooA\O
// ITEM Made by player(真天蓬:zhuz) /data/item/z/zhuz-zhuyao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 10 17:07:24 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m猪腰子[2;37;0m", ({ "zhuyao" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
一个硕大的猪腰子，晶莹剔透，看起来很有弹性[2;37;0m
腰带缘上刻着一行小字：真天蓬(zhuz)
");
	set("value", 2100000);
	set("point", 89);
	set("material", "silk");
	set("wear_msg", "$N深吸一口气，运起[1;31m龙象般若功[2;37;0m，风雷乍起，猛地长出一个[1;36m猪腰子[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;36m猪腰子[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
