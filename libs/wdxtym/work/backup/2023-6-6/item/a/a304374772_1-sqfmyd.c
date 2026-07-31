// ITEM Made by player(南巷故人:a304374772_1) /data/item/a/a304374772_1-sqfmyd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 01:22:30 2023
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m三千繁梦腰带[2;37;0m", ({ "sqfmyd" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "条");
	set("long", "这是由[1;37m世界[2;37;0m炼制而成的一条腰带。

[1;36m情不敢至深
[1;36m恐大梦一场
[1;36m卦不敢算尽
[1;36m畏天道无常[2;37;0m
腰带缘上刻着一行小字：南巷故人(a304374772_1)
");
	set("value", 200100000);
	set("point", 8800);
	set("material", "silk");
	set("wear_msg", "\n[1;36m庄生晓梦迷蝴蝶\n[1;36m望帝春心托杜鹃[2;37;0m\n");
	set("remove_msg", "\n[1;36m梦入江南烟水路\n[1;36m行尽江南\n[1;36m不与离人遇[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
