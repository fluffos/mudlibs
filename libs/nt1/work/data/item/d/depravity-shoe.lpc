// SN:\;>h]^7bQ9RG>8iP
// ITEM Made by player(堕落天使:depravity) /data/item/d/depravity-shoe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Apr  8 11:23:39 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m踏雪无痕[2;37;0m", ({ "shoe" }));
	set_weight(3600);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一双靴子。
[37m一双由干将、莫邪联手打造的靴子。[2;37;0m
靴子缘上刻着一行小字：堕落天使(depravity)
");
	set("value", 2100000);
	set("point", 105);
	set("material", "magic stone");
	set("wear_msg", "[37m$N穿起$n[37m使出轻功，视人为无物，从群众中飘闪而过。[2;37;0m\n");
	set("remove_msg", "[37m$N脱下$n[37m，以赤足在人群中慢慢走过。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
