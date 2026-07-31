// SN:\>m3C90M[YfWGmNo
// ITEM Made by player(猎人:hunterx) /data/item/h/hunterx-dji.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed May 19 18:23:15 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m九阴[1;34m神[1;31m爪[2;37;0m", ({ "dji" }));
	set_weight(2100);
	set("item_make", 1);
	set("unit", "套");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一套指套。
指套缘上刻着一行小字：猎人(hunterx)
");
	set("value", 2100000);
	set("point", 661);
	set("material", "magic stone");
	set("wear_msg", "[1;34m只见$N左手上圈下钩、左旋右转，连变了七八般花样，蓦地里右手一伸，噗的一响，五根手指直插入地上尸体的脑门。随后五根手指[1;31m血淋淋[1;34m的提将起来。[2;37;0m\n");
	set("remove_msg", "[1;34m只见$N左手上圈下钩、左旋右转，连变了七八般花样，蓦地里右手一伸，噗的一响，五根手指直插入地上尸体的脑门。随后五根手指[1;31m血淋淋[1;34m的提将起来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/finger", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/claw", 10);

	setup();
}

string long() { return query("long") + item_long(); }
