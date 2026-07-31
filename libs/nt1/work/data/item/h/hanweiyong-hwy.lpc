// SN:bNAo9dRLGHL9DQ:n
// ITEM Made by player(勇哥:hanweiyong) /data/item/h/hanweiyong-hwy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug  3 12:32:39 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[33m怒斩[2;37;0m", ({ "hwy" }));
	set_weight(13500);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[36m玄铁[2;37;0m炼制而成的一双铁掌。
[36m很厉害的武器哦[2;37;0m
铁掌缘上刻着一行小字：勇哥(hanweiyong)
");
	set("value", 1500000);
	set("point", 70);
	set("material", "steel");
	set("wear_msg", "[31m世界无限大[2;37;0m\n");
	set("remove_msg", "[34m那是吹牛比的[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/strike", 10);
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
