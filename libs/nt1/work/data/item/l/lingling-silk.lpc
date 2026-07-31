// SN:P`Z@cLF]jobL31;n
// ITEM Made by player(慕容翎:lingling) /data/item/l/lingling-silk.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep 29 16:36:24 2003
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;36m映涟丝[2;37;0m", ({ "silk" }));
	set_weight(1050);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一根鞭。
[37m一卷非常柔软的细索，乃冰蚕丝所织，[2;37;0m
鞭柄上刻着一行小字：慕容翎(lingling)
");
	set("value", 2100000);
	set("point", 191);
	set("material", "silk");
	set("wield_msg", "[37m$N拿出一卷映涟丝，轻轻摊开，握在手中。[2;37;0m\n");
	set("unwield_msg", "[37m$N将映涟丝收回成卷，放回腰间。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
