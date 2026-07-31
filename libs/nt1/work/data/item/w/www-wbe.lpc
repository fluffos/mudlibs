// SN::7cML@AGh<3I7gAc
// ITEM Made by player(悟空:www) /data/item/w/www-wbe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr 22 04:56:56 2004
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m凤翅[35m紫金冠[2;37;0m", ({ "wbe" }));
	set_weight(4500);
	set("item_make", 1);
	set("unit", "顶");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一顶头盔。
龙宫收藏的宝物之一，包含无限灵气的[1;35m紫金色[2;37;0m宝冠。
南海龙王敖钦所赠。[2;37;0m
头盔缘上刻着一行小字：悟空(www)
");
	set("value", 2100000);
	set("point", 424);
	set("material", "magic stone");
	set("wear_msg", "[33m$N[33m装备[1;37m凤翅[35m紫金冠[2;37;0m[33m。[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m凤翅[35m紫金冠[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
