// ITEM Made by player(µÛÊÍÌì:s276688_1) /data/item/s/s276688_1-mietian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 19:51:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÃğÌì[2;37;0m", ({ "mietian" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;35mÉñÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
ÎÒÉúÀ´¾ÍÊÇÏªÁ÷¶ø·Ç¸ßÉ½£¬ÎÒÓûÓÚËêÔÂÖ®Í¾×²ËéÑöÖ¹µÄÎ¡¶ë¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµÛÊÍÌì(s276688_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "ÎÒÉúÀ´¾ÍÊÇ²İ½æ¶ø·ÇÈË½Ü£¬ÎÒÈ¼ÆğÁÇÔ­Ö®»ğÖË¿¾è­è²µÄĞÇºÓ¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
