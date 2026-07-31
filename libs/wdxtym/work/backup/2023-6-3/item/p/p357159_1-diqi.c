// ITEM Made by player(¹Ş×Ó:p357159_1) /data/item/p/p357159_1-diqi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 27 22:12:29 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33mµÛÆğ[2;37;0m", ({ "diqi" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33m½£¿´ÉÏÈ¥Æ½Æ½ÎŞÆæ£¬¿ÉÉÏÃæµÄ[1;31m·ûÎÄ[1;33mÈ´ÒıÈË×¢Ä¿£¬Ò»¸ö¸ö·ûÎÄ½»´í£¬É¢·¢³öÆæÒìµÄ¹â²Ê[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¹Ş×Ó(p357159_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "$n»º»º³öÇÊ£¬ö®Ê±¼ä×ÏÆø¶«À´ÈıÍòÀï£¬Ìì¿ÕÖĞ³öÏÖËÄÊŞĞéÏñ£¬ÁîÈËÌ¾Îª¹ÛÖ¹[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
