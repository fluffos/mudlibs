// SN:ODLW?eJC\VAAk37`
// ITEM Made by player(战歌:orc) /data/item/o/orc-jue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Feb 12 01:04:58 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[36m七绝刀[2;37;0m", ({ "jue" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;31m心、欲、爱、恨、情、仇、魂一一断绝。[2;37;0m
刀柄上刻着一行小字：战歌(orc)
");
	set("value", 2100000);
	set("point", 233);
	set("material", "magic stone");
	set("wield_msg", "[1;31m一用七绝七情皆绝。[2;37;0m\n");
	set("unwield_msg", "[1;31m见血才归[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
