// SN:O3_\H0@>>Jo;HjJS
// ITEM Made by player(慕容痴:huo) /data/item/h/huo-blade.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sat May 22 00:07:42 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[35m铁木神刀[2;37;0m", ({ "blade" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;31m此用万年铁木所制，水火不浸[2;37;0m
刀柄上刻着一行小字：慕容痴(huo)
");
	set("value", 2100000);
	set("point", 291);
	set("material", "magic stone");
	set("wield_msg", "[1;33m$N[35m伸手一抖，抽出一把锋利白色木刀[2;37;0m\n");
	set("unwield_msg", "[35m$N随手一挥，$n[35m已入鞘内。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
