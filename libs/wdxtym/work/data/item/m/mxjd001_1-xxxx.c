// ITEM Made by player(Ìì³½Ò¹»Ê:mxjd001_1) /data/item/m/mxjd001_1-xxxx.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 26 15:29:48 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÇà[1;32mÁ«[1;36m½£[2;37;0m", ({ "xxxx" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÌì³½Ò¹»Ê(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;35m·ïÙâ·ïÙâ¹é¹ÊÏç£¬åÛÓÎËÄº£ÇóÆä»Ë¡£[2;37;0m\n");
	set("unwield_msg", "[1;36mÓÀÉú²»¹ıÊÇ³¡»ÃÃÎ£¬Î¨ÎáËù°®²»Ğà¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
