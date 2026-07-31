// SN:nHfgd\RcZiNc>aBN
// ITEM Made by player(胡小僧:loop) /data/item/l/loop-xuantie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Feb 19 14:07:52 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m玄铁剑[2;37;0m", ({ "xuantie" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
此剑长七尺，黝黑黝黑，沉重无比，无锋无刃，却杀气森然，实乃天下第一神兵。[2;37;0m
剑柄上刻着一行小字：胡小僧(loop)
");
	set("value", 2100000);
	set("point", 309);
	set("material", "magic stone");
	set("wield_msg", "[1;33m$N嗡的一声从背后抽出$n[1;33m，但见寒气逼人，杀雾迷茫，\n方圆之内轰然雷声滚滚，肃杀万分。[2;37;0m\n");
	set("unwield_msg", "[34m$N将$n[34m插回肩后，杀气顿减。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
