// ITEM Made by player(Ğ»ÎŞºÛ:xiewuhen_1) /data/item/x/xiewuhen_1-zhuxian.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 25 23:56:40 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÖïÏÉ½£[2;37;0m", ({ "zhuxian" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;31mµ®ÉúÓÚºèÃÉÖĞµÚÒ»ÂÆ¹â£¬´Ë½£×¨¿Ë²»ËÀÖ®Éí£¬±»ÖïÏÉ½£¹¥»÷µÄÉË¿ÚÎŞ·¨¸´Ô­¡£ÍşÁ¦ÄËµ±ÊÀÖ®Ê×¡£ÒòÎªÍşÁ¦¾Ş´ó£¬×ãÓĞÄæÌìÖ®ÄÜ£¬Ê¹ÓÃÕßÒ×²úÉúÍ³ÖÎÌìÏÂµÄÏë·¨¶ø±»ÆäÖĞµÄĞ×ìåÖ®Æø·´ÊÉ£¬É±Â¾Ö®Æø¼«ÖØ¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºĞ»ÎŞºÛ(xiewuhen_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "[1;31m·ÇÍ­·ÇÌúÒà·Ç¸Ö£¬ÔøÔÚĞëÃÖÉ½ÏÂ²Ø¡£²»ÓÃÒõÑôµßµ¹Á¶£¬ÆñÎŞË®»ğ´ã·æÃ¢£¿[2;37;0m\n");
	set("unwield_msg", "[1;31mÖïÏÉÀû£¬Â¾ÏÉÍö£¬ÏİÏÉËÄ´¦Æğºì¹â¡£¾øÏÉ±ä»¯ÎŞÇîÃî£¬´óÂŞÉñÏÉÑªÈ¾ÉÑ[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
