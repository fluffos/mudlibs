// ITEM Made by player(Ï²ÑòÑò:oo00_1) /data/item/o/oo00_1-ztt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar  9 11:11:10 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÔáÌì[2;37;0m", ({ "ztt" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;35mÉñÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
ÎÒ¾ÍÊÇÎÒ£¬ÈÎºÎÊÂÎï²»×ãÓëÎÒÆ¥µĞ£¬×ÔÔÚåĞÒ£½ÔÊÇÎÒ£¬ÎÒÈçÑô¹âÎÂÅ¯×Ô¼º£¬Ò«ÑÛĞÇ¹âÈÔÊÇÎÒ¡£ÖÕÉíÃÀÀö£¬ÊÍ·Å×Ô¼º¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÏ²ÑòÑò(oo00_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "ÎÒÉúÀ´¾ÍÊÇ¸ßÉ½¶ø·ÇÏªÁ÷£¬ÎÒÓûÓÚËêÔÂÖ®Í¾×²ËéÑöÖ¹µÄÎ¡¶ë¡£[2;37;0m\n");
	set("unwield_msg", "ÎÒÉúÀ´¾ÍÊÇÈË½Ü¶ø·Ç²İ½æ£¬ÎÒÈ¼ÆğÁÇÔ­Ö®»ğÖË¿¾è­è²µÄĞÇºÓ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
