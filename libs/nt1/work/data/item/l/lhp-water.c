// SN:dD7CRnP_Ze4AD`D\
// ITEM Made by player(少龙:lhp) /data/item/l/lhp-water.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jun  9 13:55:54 2004
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m小桥流水[2;37;0m", ({ "water" }));
	set_weight(3000);
	set("item_make", 1);
	set("unit", "对");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一对护腕。
[1;32m枯藤老树昏鸦，小桥流水人家，古道西风瘦马，夕阳西下，断肠人在天涯。[2;37;0m
护腕缘上刻着一行小字：少龙(lhp)
");
	set("value", 2100000);
	set("point", 170);
	set("material", "magic stone");
	set("wear_msg", "[1;35m红藕香残玉簟秋。轻解罗裳，独上兰舟。云中谁寄锦书来？雁字回时，月满西楼。[2;37;0m\n");
	set("remove_msg", "[1;36m花自飘零水自流。一种相思，两处闲愁。此情无计可消除，才下眉头，却上心头。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dagger", apply_armor() / 6 + 1);
	set("armor_prop/blade", apply_armor() / 6 + 1);
	set("armor_prop/whip", apply_armor() / 6 + 1);
	set("armor_prop/club", apply_armor() / 6 + 1);
	set("armor_prop/staff", apply_armor() / 6 + 1);
	set("armor_prop/finger", apply_armor() / 6 + 1);
	set("armor_prop/hand", apply_armor() / 6 + 1);
	set("armor_prop/stick", apply_armor() / 6 + 1);
	set("armor_prop/strike", apply_armor() / 6 + 1);
	set("armor_prop/claw", apply_armor() / 6 + 1);
	set("armor_prop/cuff", apply_armor() / 6 + 1);
	set("armor_prop/armor", apply_armor());
	set("armor_prop/sword", apply_armor() / 6 + 1);
	set("armor_prop/parry", apply_armor() / 6 + 1);
	set("armor_prop/hammer", apply_armor() / 6 + 1);
	set("armor_prop/unarmed", apply_armor() / 6 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
