// ITEM Made by player(ÄÏÏï¹ÊÈË:a304374772_1) /data/item/a/a304374772_1-yzgm.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar  6 00:47:12 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÔÂÖ®¹âÃ¢[2;37;0m", ({ "yzgm" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£

[1;36m½­ÌìÒ»É«ÎŞÏË³¾
[1;36mğ¨ğ¨¿ÕÖĞ¹ÂÔÂÂÖ
[1;36m½­ÅÏºÎÈË³õ¼ûÔÂ
[1;36m½­ÔÂºÎÄê³õÕÕÈË[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÏÏï¹ÊÈË(a304374772_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "\n[1;36mÔÂ¹âÉ«£¬Å®×ÓÏã\n[1;36m½£¶ÏÀá£¬Çé¶à³¤\n[1;36mÍûÃ÷ÔÂ£¬ĞÄ±¯Á¹\n[1;36mÇ§¹ÅºŞ£¬ÂÖ»Ø³¢[2;37;0m\n");
	set("unwield_msg", "[1;36mÒ»±ğĞÇÇÅÒ¹\n[1;36mÈıÒÆ¶·±ú´º\n[1;36mĞ±ººÏşÒÀÒÀ\n[1;36m°µÕİ»¹´Ù»ú[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
