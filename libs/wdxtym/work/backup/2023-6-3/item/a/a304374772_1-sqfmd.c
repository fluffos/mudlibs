// ITEM Made by player(ÄÏÏï¹ÊÈË:a304374772_1) /data/item/a/a304374772_1-sqfmd.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar  7 17:05:53 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36mÈıÇ§·±ÃÎµ¶[2;37;0m", ({ "sqfmd" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;37mÊÀ½ç[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£

[1;36mÁéÉ¢ºì³¾ÃìÎŞ¼£
[1;36mÔÂÃÔ°ÍÊñËÆÄ¾ÈË
[1;36mËªÒ¶Îè½£ÕæËÆ¼Ù
[1;36mºüÃÄÇé³ğÓĞ»¹ÎŞ
[1;36mµ¶½£»ÔÓ³ÇéÄÑ½û
[1;36m¶÷Ô¹¾À²øÌ¾ÎŞ·İ
[1;36mÇ§ÀïÑÌ²¨Ñ°×ÙÓ°
[1;36mÉñÄ§ÂÒÎèÂÒÑÌ³¾[2;37;0m
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÄÏÏï¹ÊÈË(a304374772_1)
");
	set("value", 200100000);
	set("point", 22000);
	set("material", "silk");
	set("wield_msg", "\n[1;36mÊ®²½É±Ò»ÈË\n[1;36mÇ§Àï²»ÁôĞĞ[2;37;0m\n");
	set("unwield_msg", "\n[1;36mÕİÁúÒÑ¾ªÃß\n[1;36mÒ»Ğ¥¶¯Ç§É½[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
