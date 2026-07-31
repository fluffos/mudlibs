// SN:JZoSmNm58Q:YLR[;
// ITEM Made by player(李太白:libai) /data/item/l/libai-mystrike.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Fri Dec 26 14:58:17 2003
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m血魔之手[2;37;0m", ({ "mystrike" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
隐隐发出阵阵血光。[2;37;0m
铁掌缘上刻着一行小字：李太白(libai)
");
	set("value", 2100000);
	set("point", 238);
	set("material", "magic stone");
	set("wear_msg", "[1;36m$N戴上$n[1;36m，空气中顿时充满了血腥气息。[2;37;0m\n");
	set("remove_msg", "[1;36m$N收起$n[1;36m，空气中血腥气息顿时一敛。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", 10);
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
