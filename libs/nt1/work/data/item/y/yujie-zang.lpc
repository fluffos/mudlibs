// SN:LH>nkAj>A3AUS3CY
// ITEM Made by player(一地鸡毛:yujie) /data/item/y/yujie-zang.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Nov 10 22:30:47 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[37m无[1;33m名[1;31m掌[2;37;0m", ({ "zang" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
一把锋利无名掌它在阳光下闪闪发光[2;37;0m
铁掌缘上刻着一行小字：一地鸡毛(yujie)
");
	set("value", 2100000);
	set("point", 129);
	set("material", "magic stone");
	set("wear_msg", "突然天空中一道七彩霞光笼罩四方，转瞬即逝[2;37;0m\n");
	set("remove_msg", "突然天空中一道七彩霞光笼罩四方，转瞬即逝[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
