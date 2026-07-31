// ITEM Made by player(ÄÏÏï¹ÊÈË:a304374772_1) /data/item/a/a304374772_1-sqfmzt.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Mar  9 13:03:54 2023
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÈıÇ§·±Ö¸Ì×[2;37;0m", ({ "sqfmzt" }));
	set_weight(175);
	set("item_make", 1);
	set("unit", "Ì×");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»Ì×Ö¸Ì×¡£

[1;36mÇé²»¸ÒÖÁÉî
[1;36m¿Ö´óÃÎÒ»³¡
[1;36mØÔ²»¸ÒËã¾¡
[1;36mÎ·ÌìµÀÎŞ³£[2;37;0m
Ö¸Ì×ÔµÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÏÏï¹ÊÈË(a304374772_1)
");
	set("value", 200100000);
	set("point", 10000);
	set("material", "silk");
	set("wear_msg", "\n[1;36m×¯ÉúÏşÃÎÃÔºûµû\n[1;36mÍûµÛ´ºĞÄÍĞ¶Å¾é[2;37;0m\n");
	set("remove_msg", "\n[1;36mÃÎÈë½­ÄÏÑÌË®Â·\n[1;36mĞĞ¾¡½­ÄÏ\n[1;36m²»ÓëÀëÈËÓö[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/finger", 10);
	set("armor_prop/claw", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
