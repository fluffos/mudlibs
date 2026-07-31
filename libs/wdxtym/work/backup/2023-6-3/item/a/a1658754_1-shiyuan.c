// ITEM Made by player(¶É¶É:a1658754_1) /data/item/a/a1658754_1-shiyuan.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Mar 13 21:27:28 2023
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("ÊÉÔ¹[2;37;0m", ({ "shiyuan" }));
	set_weight(750);
	set("item_make", 1);
	set("unit", "±ú");
	set("long", "ÕâÊÇÓÉ[1;37mÉîÔ¨[2;37;0mÁ¶ÖÆ¶ø³ÉµÄÒ»±ú½£¡£
ÍÌÊÉÑıÄ§¡¢ÈË¡¢¹íÉñËÀÍöÖ®Ê±Ëù²úÉúµÄÔ¹Æø[2;37;0m
½£±úÉÏ¿Ì×ÅÒ»ĞĞĞ¡×Ö£º¶É¶É(a1658754_1)
");
	set("value", 50100000);
	set("point", 5500);
	set("material", "silk");
	set("wield_msg", "ÍÌÊÉ°É[2;37;0m\n");
	set("unwield_msg", "½â·Å[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
