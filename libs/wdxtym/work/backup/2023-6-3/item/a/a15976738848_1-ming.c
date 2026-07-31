// ITEM Made by player(µÈµÈ:a15976738848_1) /data/item/a/a15976738848_1-ming.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Mar 19 23:17:53 2023
#include <ansi.h>
#include <armor.h>

inherit WAIST;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÃüÔËÖ®Éß[2;37;0m", ({ "ming" }));
	set_weight(400);
	set("item_make", 1);
	set("unit", "Ìõ");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»ÌõÑü´ø¡£
Ò»¸öÓÖÒ»¸öË®ÒøÉ«µÄ¸´ÔÓ·ûºÅÏà¼ÌÁ¬³ÉµÄÒ»Ìõ¾Ş´óĞé»ÃµÄÎŞÁÛÖ®Éß¡£
Òø°×µÄ¾ŞÉß±íÃæ£¬ÃÜÃÜÂéÂéµÄ»¨ÎÆºÍ·ûºÅ¹¹³ÉÁËÒ»¸öÓÖÒ»¸ö±Ë´ËÏàÁ¬µÄ×ªÂÖ[2;37;0m
Ñü´øÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµÈµÈ(a15976738848_1)
");
	set("value", 200100000);
	set("point", 8800);
	set("material", "silk");
	set("wear_msg", "Ê×Î²Ïà½Ó£¬ºÍÎŞÊıĞé»ÃµÄºÓÁ÷½»»ãÔÚÒ»Æğ£¬ÑÜ»¯ÎªÁËÒ»¸öÄ£ºıµÄ£¬²»¹»ÕæÊµµÄ£¬»º»º×ª¶¯µÄ¾Ş´óÔ²ÂÖ£¬¶øÔ²ÂÖµÄËÄÖÜ£¬ÓĞ¸÷ÖÖ¸÷ÑùµÄÏóÕ÷·ûºÅ´ú±í²»Í¬µÄÎ´À´¡£[2;37;0m\n");
	set("remove_msg", "ÃüÔË»Ø»·[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
