// SN:XdGE0KC4dX8_am8i
// ITEM Made by player(蓝魔:gold) /data/item/g/gold-mystrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Sep 19 10:44:16 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m大熊掌[2;37;0m", ({ "mystrike" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;32m来自长白山的一对非常肥厚的大熊掌！[2;37;0m
铁掌缘上刻着一行小字：蓝魔(gold)
");
	set("value", 2100000);
	set("point", 185);
	set("material", "magic stone");
	set("wear_msg", "[1;32m小心点，别让我的熊掌拍死啦！[2;37;0m\n");
	set("remove_msg", "[1;32m熊掌我还是留着自己和老婆吃吧！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
