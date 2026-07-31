// SN:Yf:mdl<KSMZA@8XQ
// ITEM Made by player(朱七七:zqq) /data/item/z/zqq-zqj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun 23 21:49:36 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("软猬甲[2;37;0m", ({ "zqj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
金黄色小袄[2;37;0m
护甲缘上刻着一行小字：朱七七(zqq)
");
	set("value", 2100000);
	set("point", 153);
	set("material", "magic stone");
	set("wear_msg", "盈盈一握[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了软猬甲[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
