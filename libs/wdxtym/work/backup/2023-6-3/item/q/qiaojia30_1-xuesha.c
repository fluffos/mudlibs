// ITEM Made by player(¶ÉÇÇ:qiaojia30_1) /data/item/q/qiaojia30_1-xuesha.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May  3 17:50:50 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÑªÉ±½£[2;37;0m", ({ "xuesha" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
´Ë½£Ò»³öÖÜÎ§¶ÙÊ±ÃÖÂşÑªÉ«Å¨Îí£¬µ±Å¨ÎíÉ¢¾¡ÊÇÏÔÏÖ³öÎŞÛóÖ®½£×é³ÉÎŞÛó½£Õó¡£[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶ÉÇÇ(qiaojia30_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "¿´ÉÏÈ¥¹ÖÒì¶ø²»Ê§Á¦Á¿µÄÒ»°Ñ½££¬¸øÊ¹ÓÃÕß´øÀ´ÎŞ¾¡µÄÁ¦Á¿¡£[2;37;0m\n");
	set("unwield_msg", "$NËæÊÖÒ»Ä¨£¬ÊÕÆğÁË$n¡£\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
