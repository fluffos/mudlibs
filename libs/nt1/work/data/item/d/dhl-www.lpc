// SN:0fPkcL@<2F9WA064
// ITEM Made by player(啊勇:dhl) /data/item/d/dhl-www.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Apr 25 17:46:23 2004
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m防弹衣[2;37;0m", ({ "www" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
[1;32m这是一件非常优良的防弹衣[2;37;0m
护甲缘上刻着一行小字：啊勇(dhl)
");
	set("value", 2100000);
	set("point", 80);
	set("material", "magic stone");
	set("wear_msg", "[1;31m我抖了抖发现掉了克扣子[2;37;0m\n");
	set("remove_msg", "[1;36m我大叫起来，妈的给我的还是劣质货[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/parry", apply_armor() / 15 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
