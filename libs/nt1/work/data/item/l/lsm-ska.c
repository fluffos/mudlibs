// SN:;RUA4U@fgIflD^B\
// ITEM Made by player(雷斯魔:lsm) /data/item/l/lsm-ska.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue May 11 17:16:37 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m幻影[2;37;0m", ({ "ska" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
[1;34m雷斯魔[1;34m霍霍的奸笑了几声[2;37;0m
战衣缘上刻着一行小字：雷斯魔(lsm)
");
	set("value", 2100000);
	set("point", 468);
	set("material", "silk");
	set("wear_msg", "[1;34m只见冷森森的一道青光激射而出。寒光闪烁不定，$N已入猎人的手里！[2;37;0m\n");
	set("remove_msg", "[1;34m一道幽蓝的光线划过广漠的夜空，只是一瞬间，等你想仔细看清楚时，它已消失的无影无踪。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
