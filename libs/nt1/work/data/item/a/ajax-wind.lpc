// SN:ND2DXKWXSI7dF2]e
// ITEM Made by player(疾风:ajax) /data/item/a/ajax-wind.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu May 20 15:47:08 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m风之利刃[2;37;0m", ({ "wind" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
飓风形成的一把杀人利器。[2;37;0m
剑柄上刻着一行小字：疾风(ajax)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[1;36m右手凝力，掌心出现了风之利刃。[2;37;0m\n");
	set("unwield_msg", "[35m右手一伸，风之利刃化作一阵微风，缓缓散去。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
