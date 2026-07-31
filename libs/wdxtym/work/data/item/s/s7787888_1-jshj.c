// ITEM Made by player(Ò¹³¤¸è:s7787888_1) /data/item/s/s7787888_1-jshj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Mar 22 23:13:21 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("¾øÊÀºÃ½£[2;37;0m", ({ "jshj" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;33m´«Ææ[35mÁéÊ¯[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÒ¹³¤¸è(s7787888_1)
");
	set("value", 12100000);
	set("point", 1320);
	set("material", "magic stone");
	set("wield_msg", "[1;36m$N[1;36mÒ»ÉùÇåĞ¥£¬¶¶³öÒ»±ú[1;36m$n[1;36m¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
