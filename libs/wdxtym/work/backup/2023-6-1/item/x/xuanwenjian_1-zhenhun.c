// ITEM Made by player(沈楚楚:xuanwenjian_1) /data/item/x/xuanwenjian_1-zhenhun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  3 18:08:55 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m镇魂[1;36m剑[2;37;0m", ({ "zhenhun" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m一柄巅峰魔剑，剑身杀气直冲心智，杀气环绕散发着阵阵冲霄的杀意，一不小心就会沦为杀戮机器，内敛时杀气隐伏，静如湖面，一旦爆发，山岳崩倒，大地塌陷，杀气冲天，凌冽至极[2;37;0m
剑柄上刻着一行小字：沈楚楚(xuanwenjian_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "[1;31m亿万死气，皆覆吾身。[1;33m随之破开空间从中拔出一柄散发着死气与杀气冲霄的魔剑[2;37;0m\n");
	set("unwield_msg", "[1;31m魂归天地，死气归一，[1;33m手中杀气冲霄的魔剑，杀气内敛，化作滴滴鲜血消散于周身[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
