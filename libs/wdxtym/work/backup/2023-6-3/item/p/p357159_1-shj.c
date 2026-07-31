// ITEM Made by player(¹Ş×Ó:p357159_1) /data/item/p/p357159_1-shj.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 25 21:49:00 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÉñ»ö[2;37;0m", ({ "shj" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;31m¿´ÆğÀ´Õâ°Ñ½£ºÜ²»Ïê£¬µ«ËÆºõÓÖºÜÆÕÍ¨[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¹Ş×Ó(p357159_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;31m$n»º»º³öÇÊÖÜÎ§¶ÙÊ±ÉıÆğÒ»Ë¿Á¹Òâ£¬Äã¸Ğ¾õµ½±³ºóÎ¢Î¢·¢Á¹[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
