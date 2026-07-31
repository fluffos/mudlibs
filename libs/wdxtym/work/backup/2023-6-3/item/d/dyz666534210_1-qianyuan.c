// ITEM Made by player(À¤³Ğ:dyz666534210_1) /data/item/d/dyz666534210_1-qianyuan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 25 16:29:43 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37mÇ¬Ôª[2;37;0m", ({ "qianyuan" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;33m×ÔÒ£Ô¶µÄ¹ıÈ¥Ò»Ö±´æÔÚÓÚÊÀµÄÖÕ¼«Éñ±ø
[1;36mÏóÕ÷×ÅÓÀÔ¶ÉúÉú²»Ï¢µÄÕ½¶·Ö®ĞÄ
[1;31mÎªÉú´æ¶øÕ½
[1;36mÎªÇ°½ø¶øÕ½
[1;33mÎªÕæÀí¶øÕ½£¡[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÀ¤³Ğ(dyz666534210_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;33mÒ»µÀÁ÷¹âÉÁ¹ı£¬[1;37m´«ÆæµÄÉñ½£½µÁÙ[2;37;0m\n");
	set("unwield_msg", "[1;34mºÚÒ¹²»»áÓÀÔ¶³ÖĞø£¬[1;33mµ«ÈËÀàµÄĞ½»ğÓÀ´æ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
