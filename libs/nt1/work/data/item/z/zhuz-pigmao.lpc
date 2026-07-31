// SN:neN013dN_FL^J?Td
// ITEM Made by player(真天蓬:zhuz) /data/item/z/zhuz-pigmao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Aug  7 09:31:55 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m千年猪毛[2;37;0m", ({ "pigmao" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
这是千年猪精身上的毛，坚硬如钢[2;37;0m
护甲缘上刻着一行小字：真天蓬(zhuz)
");
	set("value", 2100000);
	set("point", 178);
	set("material", "silk");
	set("wear_msg", "[33m$N[33m装备[1;37m千年猪毛[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m千年猪毛[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
