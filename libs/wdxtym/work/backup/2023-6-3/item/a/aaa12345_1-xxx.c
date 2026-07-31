// ITEM Made by player(Àî³¤Ò¹:aaa12345_1) /data/item/a/aaa12345_1-xxx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 22 16:37:20 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÖïÏÉ[31m[2;37;0m", ({ "xxx" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
Ä§µÀ×æÊ¦Åå½£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÀî³¤Ò¹(aaa12345_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "½£À´[2;37;0m\n");
	set("unwield_msg", "È¥[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
