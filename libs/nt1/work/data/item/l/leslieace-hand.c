// SN:HcN@CI<IZP>U[hlB
// ITEM Made by player(南宫图:leslieace) /data/item/l/leslieace-hand.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct 16 17:57:58 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m龙[1;33m之[1;31m掌[2;37;0m", ({ "hand" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;37m老子我的[1;31m龙[1;33m之[1;31m掌[2;37;0m
铁掌缘上刻着一行小字：南宫图(leslieace)
");
	set("value", 2100000);
	set("point", 210);
	set("material", "magic stone");
	set("wear_msg", "[1;37m敢的罪[1;37m雪域[1;31m苍狼！？“杀！[2;37;0m\n");
	set("remove_msg", "[1;37m敢的罪[1;37m雪域[1;31m苍狼！？“杀！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/hand", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/unarmed_damage", apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
