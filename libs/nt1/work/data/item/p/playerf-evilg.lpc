// SN:l=kk]h4bQGIlKaI^
// ITEM Made by player(南宫无仁:playerf) /data/item/p/playerf-evilg.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Sep 21 13:10:07 2004
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[34m恶魔之链[2;37;0m", ({ "evilg" }));
	set_weight(560);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一条腰带。
[30m这是使用九幽恶魔的[34m恶魔筋骨[30m炼制，经过恶魔之血浸泡的带有诅咒的[34m恶魔之链。[2;37;0m
腰带缘上刻着一行小字：南宫无仁(playerf)
");
	set("value", 2100000);
	set("point", 64);
	set("material", "silk");
	set("wear_msg", "$N[1;31m从九幽深潭中抓出一根[34m恶魔之链[30m缠在腰间。[2;37;0m\n");
	set("remove_msg", "$N[1;31m将[34m恶魔之链[1;31m浸入九幽深潭之中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
