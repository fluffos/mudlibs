// ITEM Made by player(µ°×Ğ:mxjd001_1) /data/item/m/mxjd001_1-oooo.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Mar 28 22:08:14 2023
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m÷Î[1;35m÷È[30m÷Í÷Ë[2;37;0m", ({ "oooo" }));
	set_weight(1);
	set("item_make", 1);
	set("unit", "°Ñ");
	set("long", "ÕâÊÇÓÉ[1;31mÕæÁú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»°Ñµ¶¡£
µ¶±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºµ°×Ğ(mxjd001_1)
");
	set("value", 300100000);
	set("point", 33000);
	set("material", "silk");
	set("wield_msg", "[1;36m¶ñ¹íÔÚÈË¼äÓÎµ´£¬ÎáµÈ¸ÃÍùºÎ·½¡£µØÓüÔçÒÑ¿Õµ´µ´£¬ÌìÌÃ¼äË­ÏàÍû¡£·ğ×æºÎÔø¶ÈÖÚÉú£¬ÈËÊÀ÷Î÷È÷Í÷Ë¡£ºÚ°µ¸ùÉîÁôÓàºŞ£¬¹âÃ÷¿É´æÉÙĞí¡£[2;37;0m\n");
	set("unwield_msg", "[1;33m¹Â·¼×ÔÉÍ£¬÷Î÷È÷Í÷Ë¡£À´À´ÍùÍù£¬ËºËéÁË°®Çé£¬Í£Ö¹ÁËÉú³¤¡£Ò²ĞíÎíÀï¿´»¨£¬¿´²»Í¸Ò»¸öËû£¬Ò²ĞíÒ»ÄîÖ®²î£¬Æ´´Õ³öÒ»¸ö¼Ò£¬ĞéÎ±µÄ¹í£¬ÉÆ±äµÄ×ì£¬°®Çé×ã¹»ÍêÃÀ¡£[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
