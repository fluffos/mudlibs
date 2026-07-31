// SN:ie43TMAIn]aGGb2d
// ITEM Made by player(悟空:www) /data/item/w/www-wba.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr 22 04:48:11 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m锁子[1;33m黄金甲[2;37;0m", ({ "wba" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
龙宫收藏的宝物之一，拥有超强防御力的宝甲。
西海龙王敖闰所赠。[2;37;0m
护甲缘上刻着一行小字：悟空(www)
");
	set("value", 2100000);
	set("point", 678);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m锁子[1;33m黄金甲[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m锁子[1;33m黄金甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
