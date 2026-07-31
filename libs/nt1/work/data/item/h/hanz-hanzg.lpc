// SN:IVPM4R[JYdjVRAVj
// ITEM Made by player(韩子奇:hanz) /data/item/h/hanz-hanzg.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Sep 29 21:08:11 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("诺基亚手机[2;37;0m", ({ "hanzg" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
这是最新款的诺基亚七六一零，时尚轻巧，实在是居家、旅游，送二奶的尚佳礼品啊[2;37;0m
指套缘上刻着一行小字：韩子奇(hanz)
");
	set("value", 2100000);
	set("point", 385);
	set("material", "magic stone");
	set("wear_msg", "$N从长衫里摸出一只手机，在下向各位郑重推荐全泥巴通，信号强，免收入网费[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了诺基亚手机[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
