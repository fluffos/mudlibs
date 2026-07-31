// SN:<TD5ak]Fig>W5FWN
// ITEM Made by player(浦饭幽助:youzhu) /data/item/y/youzhu-yblade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug  3 19:42:34 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m裁决之刃[2;37;0m", ({ "yblade" }));
	set_weight(15000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;37m寰宇天晶[2;37;0m炼制而成的一把刀。
[37m上帝用来审判罪恶的神兵，[1;37m裁决之刃！[2;37;0m
刀柄上刻着一行小字：浦饭幽助(youzhu)
");
	set("value", 4100000);
	set("point", 1962);
	set("material", "tian jing");
	set("wield_msg", "[37m正义与邪恶，生存和死亡，在此时此地，[1;37m裁决！[2;37;0m\n");
	set("unwield_msg", "[37m洗涤罪恶，净化世界，末日审判，[1;37m重生！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
