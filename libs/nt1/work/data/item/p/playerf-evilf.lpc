// SN:Gk_nYh<9G=eRb6G5
// ITEM Made by player(南宫无仁:playerf) /data/item/p/playerf-evilf.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep 21 12:58:17 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m恶魔之甲[2;37;0m", ({ "evilf" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一张护甲。
[30m这是使用九幽恶魔的[34m恶魔鳞甲[30m炼制，经过恶魔之血浸泡的带有诅咒的[34m恶魔之甲。[2;37;0m
护甲缘上刻着一行小字：南宫无仁(playerf)
");
	set("value", 2100000);
	set("point", 128);
	set("material", "silk");
	set("wear_msg", "$N[1;31m从九幽深潭中抓出一件[34m恶魔之甲[1;31m穿在身上。[2;37;0m\n");
	set("remove_msg", "$N[1;31m将[34m恶魔之甲[1;31m浸入九幽深潭之中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
