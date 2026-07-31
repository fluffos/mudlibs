// SN:n5cTES4Q=Q7A6PEU
// ITEM Made by player(消魂:gmxy) /data/item/g/gmxy-gmxz.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Jun 24 18:02:17 2004
#include <ansi.h>
#include <armor.h>

inherit HANDS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m幽魂[2;37;0m", ({ "gmxz" }));
	set_weight(2700);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双铁掌。
[1;37m消魂「嘿嘿」地奸笑了几声。[2;37;0m
铁掌缘上刻着一行小字：消魂(gmxy)
");
	set("value", 2100000);
	set("point", 440);
	set("material", "magic stone");
	set("wear_msg", "[1;37m只见冷森森的一道白光激射而出。寒光闪烁不定，$n[1;37m已入$N的手里！[2;37;0m\n");
	set("remove_msg", "[1;37m一道阴白的光线划过广漠的夜空，只是一瞬间，等你想仔细看清楚时，它已消失的无影无踪。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/unarmed_damage", apply_damage());
	set("armor_prop/strike", 10);
	set("armor_prop/armor", 10);
	set("armor_prop/hand", 10);

	setup();
}

string long() { return query("long") + item_long(); }
