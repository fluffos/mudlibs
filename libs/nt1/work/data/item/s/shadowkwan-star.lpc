// SN:DVc;6VQ3B7]hJdRI
// ITEM Made by player(独孤傲:shadowkwan) /data/item/s/shadowkwan-star.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 31 17:54:06 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m星[1;33m光[1;31m灭绝[2;37;0m", ({ "star" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
[1;32m沐浴过[1;31m女神之血[1;32m的[1;33m终极武器。[2;37;0m
指套缘上刻着一行小字：独孤傲(shadowkwan)
");
	set("value", 2100000);
	set("point", 550);
	set("material", "magic stone");
	set("wear_msg", "[1;37m霎时间一道[1;33m光华[1;37m自$n[1;37m发出，天地间一片骚动，$n[1;37m的[1;33m光华[1;37m照亮了大地，[1;37m如一道[1;36m流星[1;37m划破了[30m长空。[2;37;0m\n");
	set("remove_msg", "$n[1;37m的[1;33m光华[1;37m渐渐[30m暗淡，[1;37m大地也[1;37m恢复了[1;36m宁静。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/claw", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);

	setup();
}

string long() { return query("long") + item_long(); }
