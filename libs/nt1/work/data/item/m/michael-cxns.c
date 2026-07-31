// SN:o:Dohg4:@H@Ym`K@
// ITEM Made by player(行香子:michael) /data/item/m/michael-cxns.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Oct 12 14:27:10 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m醉花阴[2;37;0m", ({ "cxns" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;32m醉花阴[2;37;0m
铁掌缘上刻着一行小字：行香子(michael)
");
	set("value", 2100000);
	set("point", 224);
	set("material", "magic stone");
	set("wear_msg", "[1;32m薄雾浓云愁永昼，瑞脑消金兽。佳节又重阳，玉枕纱橱，半夜凉初透。[2;37;0m\n");
	set("remove_msg", "[1;32m东篱把酒黄昏後，有暗香盈袖。莫道不消魂，帘卷西风，人比黄花瘦。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);

	setup();
}

string long() { return query("long") + item_long(); }
