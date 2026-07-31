// SN:BA0\WI=TTP3VdA]=
// ITEM Made by player(唐四藏:tang) /data/item/t/tang-pao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jan 11 20:12:43 2004
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m木棉[1;33m袈裟[2;37;0m", ({ "pao" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：唐四藏(tang)
");
	set("value", 2100000);
	set("point", 256);
	set("material", "silk");
	set("wear_msg", "[33m$N穿上了$n[33m，宝相庄严，拈花一笑。[2;37;0m\n");
	set("remove_msg", "[33m$N把$n[33m脱了下来，双掌合十，淡淡一笑。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
