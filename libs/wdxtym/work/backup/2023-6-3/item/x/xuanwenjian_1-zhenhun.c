// ITEM Made by player(Éò³ş³ş:xuanwenjian_1) /data/item/x/xuanwenjian_1-zhenhun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Apr  3 18:08:55 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31mÕò»ê[1;36m½£[2;37;0m", ({ "zhenhun" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;35mÉñÌú[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
[1;31mÒ»±úáÛ·åÄ§½££¬½£ÉíÉ±ÆøÖ±³åĞÄÖÇ£¬É±Æø»·ÈÆÉ¢·¢×ÅÕóÕó³åÏöµÄÉ±Òâ£¬Ò»²»Ğ¡ĞÄ¾Í»áÂÙÎªÉ±Â¾»úÆ÷£¬ÄÚÁ²Ê±É±ÆøÒş·ü£¬¾²ÈçºşÃæ£¬Ò»µ©±¬·¢£¬É½ÔÀ±Àµ¹£¬´óµØËúÏİ£¬É±Æø³åÌì£¬ÁèÙıÖÁ¼«[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£ºÉò³ş³ş(xuanwenjian_1)
");
	set("value", 2700000);
	set("point", 286);
	set("material", "magic stone");
	set("wield_msg", "[1;31mÒÚÍòËÀÆø£¬½Ô¸²ÎáÉí¡£[1;33mËæÖ®ÆÆ¿ª¿Õ¼ä´ÓÖĞ°Î³öÒ»±úÉ¢·¢×ÅËÀÆøÓëÉ±Æø³åÏöµÄÄ§½£[2;37;0m\n");
	set("unwield_msg", "[1;31m»ê¹éÌìµØ£¬ËÀÆø¹éÒ»£¬[1;33mÊÖÖĞÉ±Æø³åÏöµÄÄ§½££¬É±ÆøÄÚÁ²£¬»¯×÷µÎµÎÏÊÑªÏûÉ¢ÓÚÖÜÉí[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
