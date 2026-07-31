// ITEM Made by player(µ°×Ğ:mxjd001_1) /data/item/m/mxjd001_1-llll.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 27 21:37:27 2023
#include <ansi.h>
#include <weapon.h>

inherit CLUB;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m¶¨[1;34mº£[1;36mÉñ[30mÕë[2;37;0m", ({ "llll" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "¸ù");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»¸ù¹÷¡£
¹÷±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµ°×Ğ(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m¹ÜËûÄÇÃ´¶à£¬ÉÏÌì°²ÅÅµÄ×î´óÂï£¡[2;37;0m\n");
	set("unwield_msg", "[1;33mÒòÎªÄã¿´ÉÏÈ¥ÏñÅ®ÈË£¬ÎÒ²Å²»ÉËº¦Äã¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_club(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
