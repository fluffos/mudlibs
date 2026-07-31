// SN:KALOCZTd2@7<E8eK
// ITEM Made by player(独孤傲:shadowkwan) /data/item/s/shadowkwan-cloth.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Jun  4 13:01:15 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m光[1;33m之[1;36m神衣[2;37;0m", ({ "cloth" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;32m沐浴过[1;31m女神之血[1;32m的[1;36m终极战袍[1;32m。[2;37;0m
战衣缘上刻着一行小字：独孤傲(shadowkwan)
");
	set("value", 2100000);
	set("point", 580);
	set("material", "silk");
	set("wear_msg", "[1;32m$N喃喃念到：[1;31m谨以神之名义，唤醒您的灵魂，请以您的神力，庇佑吾之肉身。[1;32m念毕双手摊开，突然一团[1;37m白光[1;32m包围着$N，原来$n[1;32m已经穿在$N身上，正闪烁着耀眼的[1;33m光芒[1;32m。[2;37;0m\n");
	set("remove_msg", "$n[1;32m突然化成一道[1;37m白光，[1;32m冲天直上，穿破了[1;36m云霄，[1;32m飞向[30m宇宙的深处，[1;32m继续[30m漫长的沉睡，[1;32m期待着下次的苏醒。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
