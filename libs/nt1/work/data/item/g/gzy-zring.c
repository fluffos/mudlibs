// SN:=Ve[NSTKSVTUC1LY
// ITEM Made by player(虚枫:gzy) /data/item/g/gzy-zring.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Sep 12 17:51:27 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("钻石戒指[2;37;0m", ({ "zring" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
美丽[2;37;0m
指套缘上刻着一行小字：虚枫(gzy)
");
	set("value", 2100000);
	set("point", 212);
	set("material", "magic stone");
	set("wear_msg", "[1;31m一招攻出，竟卷起千层气浪，太玄内劲顿时源源不绝透过白钻涌入体内！[2;37;0m\n");
	set("remove_msg", "[1;31m一招攻出，竟卷起千层气浪，太玄内劲顿时源源不绝透过白钻涌入体内！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/finger", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
