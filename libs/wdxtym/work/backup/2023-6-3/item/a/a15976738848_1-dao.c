// ITEM Made by player(µÈµÈ:a15976738848_1) /data/item/a/a15976738848_1-dao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat Mar 11 23:52:11 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÔªÊ¼Ö¤µÀ½£[2;37;0m", ({ "dao" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[37m»ìãçÍÍÃÉÈçÂÑ£¬[37m»è»èÄ¬Ä¬[1;36mÓ¯¿Õ¡£
[33mºÆÈ»Ì«ËØ±§ºèÃÉ¡£[33mÒ»ÆøÑ­»·ÄıÖØ¡£
[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµÈµÈ(a15976738848_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "ÔªÊ¼Ö®ÆøÃÖÂş£¬´óµÀÄÚÔÌÆäÖĞ¡£[2;37;0m\n");
	set("unwield_msg", "ÊÕ£¡[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
